/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paths_rgb_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:47:39 by bgresse           #+#    #+#             */
/*   Updated: 2023/06/01 21:39:16 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	to_much_digit(char *line)
{
	size_t i = 0;
	int l = 0;

	while (i < ft_strlen(line))
	{
		if (line[i] != ' ' && line[i] != '	')
			l++;
		i++;
	}
	if (l - 1 > 11)
		return 1;
	return 0;
}


static void	parse_rgb_values(char *line, uint8_t rgb_values[3], t_data *data)
{
	char		*start;
	char		*end;
	int			index;

	index = 0;
	start = line;
	if (to_much_digit(line))
	{
		ft_free(data->garbage);
		write(2, "Error\nToo much digit for color in file\n", 39);
		exit (1);
	}
	while (index < 3)
	{
		end = ft_strchr(start, ',');
		if (end)
			*end = '\0';
		else if (index < 2)
			return ;
		if (ft_atoi(start) > 255)
		{
			ft_free(data->garbage);
			write(2, "Error\nColor not good\n", 21);
			exit (1);
		}
		rgb_values[index] = (uint8_t)ft_atoi(start);
		start = end + 1;
		index++;
	}
}

void	get_color_value(t_data *data, t_rgb *rgb, char *line)
{
	uint8_t		rgb_values[3];

	if (line == NULL)
		return ;
	while (*line == ' ' || *line == 'F' || *line == 'C')
	{
		if (*line == 'F')
			data->map.floor_color_set += 1;
		else if (*line == 'C')
			data->map.ceiling_color_set += 1;
		line++;
	}
	parse_rgb_values(line, rgb_values, data);
	rgb->red = rgb_values[0];
	rgb->green = rgb_values[1];
	rgb->blue = rgb_values[2];
}

void	fill_map_array_line(t_data *data, char *line, int index)
{
	int		index_j;
	int		len;

	index_j = -1;
	while (++index_j < (int)ft_strlen(line))
	{
		if (line[index_j] == ' ')
			line[index_j] = '3';
		else if (line[index_j] == 'N' || line[index_j] == 'S' || \
			line[index_j] == 'E' || line[index_j] == 'W')
		{
			get_position_player(data, (float)index_j, \
			(float)index, line[index_j]);
			line[index_j] = '0';
		}
		else if (line[index_j] == '\n')
			line[index_j] = '\0';
	}
	ft_strcpy(data->map.array[index], line);
	len = ft_strlen(line);
	if (len < data->map.width)
		while (len < data->map.width)
			data->map.array[index][len++] = '3';
}

bool	fill_map_array(t_data *data, char *argv)
{
	int		file_descriptor;
	char	*line;
	int		index;

	index = -1;
	file_descriptor = open(argv, O_RDONLY);
	if (file_descriptor < 0)
		return (perror("open file descriptor"), false);
	line = get_next_line(data, file_descriptor);
	while (line != NULL && (++index < data->map.start_line || line[0] == '\n'))
	{
		line = get_next_line(data, file_descriptor);
	}
	index = 0;
	while (line != NULL)
	{
		if (line[0] == '\n')
			break ;
		fill_map_array_line(data, line, index);
		line = get_next_line(data, file_descriptor);
		index++;
	}
	if (close(file_descriptor) < 0)
		return (perror("close file descriptor"), false);
	return (true);
}
