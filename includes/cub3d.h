/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 22:12:09 by jcluzet           #+#    #+#             */
/*   Updated: 2023/06/07 12:43:46 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <string.h> 
# include <stdint.h>
# include "garbage.h"
# include "vectors.h"
# include "structs.h"

# if defined(__APPLE__) && defined(__MACH__)
#  define ADVANCE 13
#  define BACK 1
#  define RIGHT 2
#  define LEFT 0
#  define ROT_RIGHT 124
#  define ROT_LEFT 123
#  define ESC 53
#  define RED_BUTTON 79
#  define LIGHTS 29
#  define CLOSERED 17
# else
#  define ADVANCE 119
#  define BACK 115
#  define RIGHT 100
#  define LEFT 97
#  define ROT_RIGHT 65363
#  define ROT_LEFT 65361
#  define ESC 65307
#  define RED_BUTTON 79
#  define LIGHTS 48
#  define CLOSERED 33
# endif

# define WIN_W 1400
# define WIN_H 1000
# define R 0.04f
# define SCREEN_DIST 0.5f 
# define SPEED 0.2f

# include "minimap.h"

/* check1_functions.c */

bool		textures_are_valid(t_data *data);
bool		is_map_line(char *line);
bool		check_value_of_map(t_data *data, char *line, int file_descriptor);
bool		check_validity_of_map(t_data *data, char *argv);

/* check2_functions.c */

bool		paths_rgb_are_filled(t_data *data);
bool		map_unclosed(t_data *data, int x, int y, bool **visited);
bool		cube_parser(t_data *data, char *argv);

/* init_functions.c */

bool		init_data(t_data *data);

/* parse_map_functions.c */

bool		get_size_of_map(t_data *data, char *argv);
bool		malloc_map_visited(t_data *data);
void		get_position_player(t_data *data, float x, float y, char dir_base);
void		fill_map_array_line(t_data *data, char *line, int index);
bool		fill_map_array(t_data *data, char *argv);

/* parse_paths_rgb_functions.c */

void		get_color_value(t_data *data, t_rgb *rgb, char *line);
void		get_path_value(t_data *data, char **path, char *line);
void		fill_paths_rgb(t_data *data, char *line);
bool		paths_rgb_duplicate(t_data *data);
bool		get_file_paths_rgb(t_data *data, char *argv);

/* set_colors */

int			rgb_to_int(t_rgb color);
int			set_color_cell(t_data *data, int x, int y);

/* utils1_functions.c */

size_t		ft_strlen(const char *str);
char		*ft_strdup(t_data *data, const char *src);
int			ft_atoi(const char *str);

/* utils2_functions.c */

char		*get_next_line(t_data *data, int fd);
void		*ft_calloc(t_data *data, size_t num, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strndup(t_data *data, const char *src, size_t n);

/* handler.c */

int			handle_keypress(int keycode, t_data *data);
int			handle_keyrelease(int keycode, t_data *data);
void		handle_direction(t_data *data, double *new_x, double *new_y);
void		handle_rotation(t_data *data);
void		update_player(t_data *data);

/* mlx_utils.c */

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			loop_hook(t_data *data);
void		display_game(t_data *data);

/* raycasting.c */

void		raycasting(t_data *data);
void		dda_algo(t_data *data);
void		calc_wall(t_data *data, int x);

char		*ft_strstr(const char *big, const char *little);
int			ft_strncmp(const char *s1, const char *s2, size_t length);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dest, const char *src);

int         close_win(t_data *data);
int         is_equal(char c, char c2);

#endif