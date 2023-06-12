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
