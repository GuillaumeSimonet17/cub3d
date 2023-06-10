/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 22:12:09 by jcluzet           #+#    #+#             */
/*   Updated: 2023/06/07 12:43:46 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_rgb
{
	uint8_t			red;
	uint8_t			green;
	uint8_t			blue;
}	t_rgb;

typedef struct s_params
{
	char			*path_to_the_north_texture;
	char			*path_to_the_south_texture;
	char			*path_to_the_west_texture;
	char			*path_to_the_east_texture;
	t_rgb			celling_rgb;
	t_rgb			floor_rgb;
	int				celling_color;
	int				floor_color;
}	t_params;

typedef struct s_player
{
	t_float_vector	pos;
	t_float_vector	dir;
	t_float_vector	plane;
	t_float_vector	move;
	char			dir_base;
	float			angle;
}	t_player;

typedef struct s_ray
{
	t_float_vector	pos;
	t_float_vector	dir;
	t_float_vector	side_dist;
	t_float_vector	delta_dist;
	t_float_vector	camera;
	t_int_vector	map;
	t_int_vector	step;
	float			perp_wall_dist;
	bool			hit;
	int				side;
	int				drawend;
	int				drawstart;
	double			wallx;
	int				texnum;
	int				lineheight;
	int				d;
	int				texx;
	int				texy;
	int				color;
	int				y;
}	t_ray;

typedef struct s_map
{
	int				no_path_set;
	int				we_path_set;
	int				so_path_set;
	int				ea_path_set;
	int				floor_color_set;
	int				ceiling_color_set;
	bool			before_params;
	int				start_line;
	int				num_of_player;
	char			**array;
	bool			**visited;
	int				width;
	int				height;
}	t_map;

typedef struct s_win
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_win;

typedef struct s_keys
{
	bool			advance;
	bool			back;
	bool			right;
	bool			left;
	bool			rot_right;
	bool			rot_left;
}	t_keys;

typedef struct s_img
{
	void		*img;
	char		*data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}	t_img;

typedef struct s_data
{
	t_m_free		*garbage;
	t_map			map;
	t_player		player;
	t_params		params;
	t_win			win;
	t_ray			ray;
	t_keys			keys;
	t_img			text[4];
}	t_data;

#endif // STRUCTS_H