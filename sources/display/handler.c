/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:40:42 by bgresse           #+#    #+#             */
/*   Updated: 2023/06/08 15:30:44 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_right(t_data *data)
{
	double	odrx;
	double	opx;

	odrx = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(R) - data->player.dir.y
		* sin(R);
	data->player.dir.y = odrx * sin(R) + data->player.dir.y * cos(R);
	opx = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(R)
		- data->player.plane.y * sin(R);
	data->player.plane.y = opx * sin(R) + data->player.plane.y * cos(R);
}

void	rotate_left(t_data *data)
{
	double	odrx;
	double	opx;

	odrx = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(-R) - data->player.dir.y
		* sin(-R);
	data->player.dir.y = odrx * sin(-R) + data->player.dir.y * cos(-R);
	opx = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(-R)
		- data->player.plane.y * sin(-R);
	data->player.plane.y = opx * sin(-R) + data->player.plane.y * cos(-R);
}

void	handle_rotation(t_data *data)
{
	if (data->keys.rot_right)
		rotate_right(data);
	else if (data->keys.rot_left)
		rotate_left(data);
}

int	is_equal(char c, char c2)
{
	if (c2 == c)
			return (1);
	return (0);
}

void	update_player(t_data *data)
{
	double	new_x;
	double	new_y;
    int		is_wall;
	float	dx;
	float	dy;
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
		// is_wall = (int)(data->player.pos.y + SCREEN_DIST * \
		// data->player.dir.x * data->player.move.x);
		// printf("%d\n", is_wall);
		// if (data->player.move.x > 1 && data->map.array[(int)data->player.pos.y][is_wall])
		// {
		// 	dy = SPEED * data->player.dir.x * data->player.move.x;
		// 	data->player.pos.y += dy;
		// }
		// else if (data->player.move.x < 1)
		// {

		// }
		// if (data->player.move.y > 1)
		// {

		// }
		// else if (data->player.move.x < 1)
		// {

		// }
		// data->player.pos.x = new_x;
		// data->player.pos.y = new_y;
		is_wall = (int)(data->player.pos.x + -SCREEN_DIST * \
		data->player.dir.y * data->player.move.x);
		int tmp = data->map.array[(int)(data->player.pos.y)][is_wall];
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
		is_wall = (int)(data->player.pos.x + SCREEN_DIST  * \
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
