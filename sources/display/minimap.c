/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:39:57 by bgresse           #+#    #+#             */
/*   Updated: 2023/06/07 12:45:05 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_minimap_color(t_data *data, int x, int y)
{
	int	color;

	color = 0;
	if (y == (int)data->player.pos.y && x == (int)data->player.pos.x)
		color = 0xFF0000;
	else if (data->map.array[y][x] == '0')
		color = 0xFFFFFF;
	else if (data->map.array[y][x] == '1')
		color = 0x000000;
	return (color);
}

void	draw_minimap(t_data *data)
{
	int		x;
	int		y;
	int		dy;
	int		dx;
	int		color;

	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
		{
			color = get_minimap_color(data, x, y);
			dy = -1;
			while (++dy < MINIMAP_SIZE)
			{
				dx = -1;
				while (++dx < MINIMAP_SIZE)
					my_mlx_pixel_put(data, x * MINIMAP_SIZE
						+ dx, y * MINIMAP_SIZE + dy, color);
			}
		}
	}
}
