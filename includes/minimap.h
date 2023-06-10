/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:26:01 by bgresse           #+#    #+#             */
/*   Updated: 2023/05/09 14:26:06 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINIMAP_SIZE 10

bool		load_textures(t_data *data); // a finir
int			get_minimap_color(t_data *data, int x, int y);
void		draw_minimap(t_data *data);

#endif // MINIMAP_H