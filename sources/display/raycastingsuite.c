/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingsuite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:10:17 by bgresse           #+#    #+#             */
/*   Updated: 2023/06/07 12:46:17 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	raycasting(t_data *data)
{
	int	column_pix;

	column_pix = -1;
	while (++column_pix < WIN_W)
	{
		data->ray.camera.x = 2 * column_pix / (double)WIN_W - 1;
		data->ray.dir.x = data->player.dir.x + data->player.plane.x
			* data->ray.camera.x;
		data->ray.dir.y = data->player.dir.y + data->player.plane.y
			* data->ray.camera.x;
		dda_algo(data);
		calc_wall(data, column_pix);
	}
}

void	update_step_and_side_dist(t_data *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.side_dist.x = (data->player.pos.x
				- data->ray.map.x) * data->ray.delta_dist.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.side_dist.x = (data->ray.map.x + 1.0
				- data->player.pos.x) * data->ray.delta_dist.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.side_dist.y = (data->player.pos.y
				- data->ray.map.y) * data->ray.delta_dist.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.side_dist.y = (data->ray.map.y + 1.0
				- data->player.pos.y) * data->ray.delta_dist.y;
	}
}

void	perform_dda(t_data *data)
{
	data->ray.hit = 0;
	data->ray.side = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta_dist.x;
			data->ray.map.x += data->ray.step.x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta_dist.y;
			data->ray.map.y += data->ray.step.y;
			data->ray.side = 1;
		}
		if (data->map.array[data->ray.map.y][data->ray.map.x] == '1')
			data->ray.hit = 1;
	}
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = (data->ray.side_dist.x
				- data->ray.delta_dist.x);
	else
		data->ray.perp_wall_dist = (data->ray.side_dist.y
				- data->ray.delta_dist.y);
}

void	dda_algo(t_data *data)
{
	data->ray.map.x = (int)data->player.pos.x;
	data->ray.map.y = (int)data->player.pos.y;
	if (data->ray.dir.x == 0)
		data->ray.delta_dist.x = 1e30;
	else
		data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
	if (data->ray.dir.y == 0)
		data->ray.delta_dist.y = 1e30;
	else
		data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
	update_step_and_side_dist(data);
	perform_dda(data);
}
