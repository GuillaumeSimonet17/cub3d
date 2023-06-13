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

typedef struct s_temp
{
	double	new_x;
	double	new_y;
	int		is_wall;
	float	dx;
	float	dy;
	int		tmp;
}	t_temp;

void	move_y(t_data *data, t_temp tmp)
{
	tmp.is_wall = (int)(data->player.pos.x + -SCREEN_DIST * \
	data->player.dir.y * data->player.move.x);
	tmp.tmp = data->map.array[(int)(data->player.pos.y)][tmp.is_wall];
	if (is_equal(tmp.tmp, '0'))
	{
		tmp.dx = -SPEED * data->player.dir.y * data->player.move.x;
		data->player.pos.x += tmp.dx;
	}
	tmp.is_wall = (int)(data->player.pos.y + SCREEN_DIST * \
		data->player.dir.x * data->player.move.x);
	tmp.tmp = data->map.array[tmp.is_wall][(int)(data->player.pos.x)];
	if (is_equal(tmp.tmp, '0'))
	{
		tmp.dy = SPEED * data->player.dir.x * data->player.move.x;
		data->player.pos.y += tmp.dy;
	}
}

void	move_x(t_data *data, t_temp tmp)
{
	tmp.is_wall = (int)(data->player.pos.x + SCREEN_DIST * \
		data->player.dir.x * data->player.move.y);
	tmp.tmp = data->map.array[(int)(data->player.pos.y)][tmp.is_wall];
	if (is_equal(tmp.tmp, '0'))
	{
		tmp.dx = SPEED * data->player.dir.x * data->player.move.y;
		data->player.pos.x += tmp.dx;
	}
	tmp.is_wall = (int)(data->player.pos.y + SCREEN_DIST * \
		data->player.dir.y * data->player.move.y);
	tmp.tmp = data->map.array[tmp.is_wall][(int)(data->player.pos.x)];
	if (is_equal(tmp.tmp, '0'))
	{
		tmp.dy = SPEED * data->player.dir.y * data->player.move.y;
		data->player.pos.y += tmp.dy;
	}
}

void	update_player(t_data *data)
{
	t_temp	tmp;

	tmp.new_x = 0;
	tmp.new_y = 0;
	if (data->keys.advance || data->keys.back
		|| data->keys.right || data->keys.left)
		handle_direction(data, &tmp.new_x, &tmp.new_y);
	else if (data->keys.rot_right || data->keys.rot_left)
		handle_rotation(data);
	if (tmp.new_x >= 0 && tmp.new_x <= data->map.width
		&& tmp.new_y >= 0 && tmp.new_y
		<= data->map.height)
	{
		move_y(data, tmp);
		move_x(data, tmp);
	}
}
