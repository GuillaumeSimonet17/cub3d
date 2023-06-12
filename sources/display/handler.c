/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:40:42 by bgresse           #+#    #+#             */
/*   Updated: 2023/06/07 12:42:21 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ADVANCE)
	{
		data->player.move.y = 1;
		data->keys.advance = true;
	}
	if (keycode == BACK)
	{
		data->player.move.y = -1;
		data->keys.back = true;
	}
	if (keycode == RIGHT)
	{
		data->player.move.x = 1;
		data->keys.right = true;
	}
	if (keycode == LEFT)
	{
		data->player.move.x = -1;
		data->keys.left = true;
	}
	if (keycode == ROT_LEFT)
		data->keys.rot_left = true;
	if (keycode == ROT_RIGHT)
		data->keys.rot_right = true;
	if (keycode == ESC)
	{
		ft_free(data->garbage);
		exit(0);
	}
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == ADVANCE)
	{
		data->player.move.y = 0;
		data->keys.advance = false;
	}
	if (keycode == BACK)
	{
		data->player.move.y = 0;
		data->keys.back = false;
	}
	if (keycode == RIGHT)
	{
		data->player.move.x = 0;
		data->keys.right = false;
	}
	if (keycode == LEFT)
	{
		data->player.move.x = 0;
		data->keys.left = false;
	}
	if (keycode == ROT_LEFT)
		data->keys.rot_left = false;
	if (keycode == ROT_RIGHT)
		data->keys.rot_right = false;
	return (0);
}

void	handle_direction(t_data *data, double *new_x, double *new_y)
{
	if (data->keys.advance)
	{
		*new_x = data->player.pos.x + SPEED * data->player.dir.x;
		*new_y = data->player.pos.y + SPEED * data->player.dir.y;
	}
	else if (data->keys.back)
	{
		*new_x = data->player.pos.x - SPEED * data->player.dir.x;
		*new_y = data->player.pos.y - SPEED * data->player.dir.y;
	}
	else if (data->keys.right)
	{
		*new_x = data->player.pos.x + SPEED * data->player.plane.x;
		*new_y = data->player.pos.y + SPEED * data->player.plane.y;
	}
	else if (data->keys.left)
	{
		*new_x = data->player.pos.x - SPEED * data->player.plane.x;
		*new_y = data->player.pos.y - SPEED * data->player.plane.y;
	}
}
