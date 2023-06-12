/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:40:42 by bgresse           #+#    #+#             */
/*   Updated: 2023/06/08 15:30:44 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_player(t_data *data)
{
	double	new_x;
	double	new_y;
	int		is_wall;
	float	dx;
	float	dy;
	int		tmp;

	new_x = 0;
	new_y = 0;
	if (data->keys.advance || data->keys.back
		|| data->keys.right || data->keys.left)
		handle_direction(data, &new_x, &new_y);
	else if (data->keys.rot_right || data->keys.rot_left)
		handle_rotation(data);
	if (new_x >= 0 && new_x <= data->map.width && new_y >= 0 && new_y
		<= data->map.height)
	{
		is_wall = (int)(data->player.pos.x + -SCREEN_DIST * \
		data->player.dir.y * data->player.move.x);
		tmp = data->map.array[(int)(data->player.pos.y)][is_wall];
		if (is_equal(tmp, '0'))
		{
			dx = -SPEED * data->player.dir.y * data->player.move.x;
			data->player.pos.x += dx;
		}
		is_wall = (int)(data->player.pos.y + SCREEN_DIST * \
			data->player.dir.x * data->player.move.x);
		tmp = data->map.array[is_wall][(int)(data->player.pos.x)];
		if (is_equal(tmp, '0'))
		{
			dy = SPEED * data->player.dir.x * data->player.move.x;
			data->player.pos.y += dy;
		}
		is_wall = (int)(data->player.pos.x + SCREEN_DIST * \
			data->player.dir.x * data->player.move.y);
		tmp = data->map.array[(int)(data->player.pos.y)][is_wall];
		if (is_equal(tmp, '0'))
		{
			dx = SPEED * data->player.dir.x * data->player.move.y;
			data->player.pos.x += dx;
		}
		is_wall = (int)(data->player.pos.y + SCREEN_DIST * \
			data->player.dir.y * data->player.move.y);
		tmp = data->map.array[is_wall][(int)(data->player.pos.x)];
		if (is_equal(tmp, '0'))
		{
			dy = SPEED * data->player.dir.y * data->player.move.y;
			data->player.pos.y += dy;
		}
	}
}
