/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:10:17 by bgresse           #+#    #+#             */
/*   Updated: 2023/06/07 12:46:17 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_col_loop(t_data *data, int x)
{
	while (data->ray.y < WIN_H)
	{
		if (data->ray.y < data->ray.drawstart)
			my_mlx_pixel_put(data, x, data->ray.y, data->params.celling_color);
		else if (data->ray.y >= data->ray.drawstart
			&& data->ray.y < data->ray.drawend)
		{
			data->ray.d = data->ray.y * 256 - WIN_H
				* 128 + data->ray.lineheight * 128;
			data->ray.texy = ((data->ray.d
						* data->text[data->ray.texnum].height)
					/ data->ray.lineheight) / 256;
			data->ray.color = *(int *)(data->text[data->ray.texnum].data
					+ ((data->ray.texy * data->text[data->ray.texnum].size_line)
						+ data->ray.texx
						* (data->text[data->ray.texnum].bpp / 8)));
			my_mlx_pixel_put(data, x, data->ray.y, data->ray.color);
		}
		else if (data->ray.y >= data->ray.drawend)
			my_mlx_pixel_put(data, x, data->ray.y, data->params.floor_color);
		data->ray.y++;
	}
}

void	ft_draw_col(t_data *data, int x)
{
	data->ray.y = 0;
	data->ray.texx = (int)(data->ray.wallx
			* (double)(data->text[data->ray.texnum].width));
	if ((data->ray.side == 0 && data->ray.dir.x < 0)
		|| (data->ray.side == 1 && data->ray.dir.y > 0))
		data->ray.texx = data->text[data->ray.texnum].width
			- data->ray.texx - 1;
	draw_col_loop(data, x);
}

void	set_tex_num(t_data *data)
{
	data->ray.texnum = 2;
	if (data->ray.side == 0)
	{
		if (data->ray.dir.x > 0)
			data->ray.texnum = 1;
		else
			data->ray.texnum = 0;
	}
	else
	{
		if (data->ray.dir.y > 0)
			data->ray.texnum = 3;
	}
}

void	calc_draw_range(t_data *data)
{
	data->ray.drawstart = -data->ray.lineheight / 2 + WIN_H / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = data->ray.lineheight / 2 + WIN_H / 2;
	if (data->ray.drawend >= WIN_H)
		data->ray.drawend = WIN_H - 1;
}

void	calc_wall(t_data *data, int x)
{
	data->ray.lineheight = (int)(WIN_H / data->ray.perp_wall_dist);
	set_tex_num(data);
	calc_draw_range(data);
	if (data->ray.side == 0)
		data->ray.wallx = data->player.pos.y
			+ data->ray.perp_wall_dist * data->ray.dir.y;
	else
		data->ray.wallx = data->player.pos.x
			+ data->ray.perp_wall_dist * data->ray.dir.x;
	data->ray.wallx -= floor(data->ray.wallx);
	ft_draw_col(data, x);
}
