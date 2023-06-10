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

void	set_texture_paths(t_data *data, char *texture_paths[4])
{
	texture_paths[0] = data->params.path_to_the_north_texture;
	texture_paths[1] = data->params.path_to_the_south_texture;
	texture_paths[2] = data->params.path_to_the_west_texture;
	texture_paths[3] = data->params.path_to_the_east_texture;
}

bool	load_individual_texture(t_data *data, int index, char *texture_path)
{
	data->text[index].width = 64;
	data->text[index].height = 64;
	data->text[index].img = mlx_xpm_file_to_image(data->win.mlx,
			texture_path, &data->text[index].width, &data->text[index].height);
	if (!data->text[index].img)
	{
		fprintf(stderr, "Failed to load texture: %s\n", texture_path);
		exit(1);
	}
	data->text[index].data = mlx_get_data_addr(data->text[index].img,
			&data->text[index].bpp, &data->text[index].size_line,
			&data->text[index].endian);
	return (true);
}

bool	load_textures(t_data *data)
{
	char	*texture_paths[4];
	int		i;

	set_texture_paths(data, texture_paths);
	i = -1;
	while (++i < 4)
	{
		if (!load_individual_texture(data, i, texture_paths[i]))
			return (false);
	}
	return (true);
}
