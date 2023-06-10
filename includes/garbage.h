/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:32:34 by bgresse           #+#    #+#             */
/*   Updated: 2023/05/16 15:51:50 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

typedef struct s_free
{
	void			*ptr;
	struct s_free	*next;
}					t_free;

typedef struct s_m_free
{
	struct s_free	*list;
}				t_m_free;

t_m_free	*free_init(void);

void		ft_free(t_m_free *m_free);
void		*free_malloc(t_m_free *m_free, size_t size);
void		free_remove(t_m_free *m_free, void *ptr);
void		free_remove_if(t_free **begin_list, void *ptr_ref);
int			free_add(t_m_free *m_free, void *ptr);
int			free_add_value(t_m_free *m_free, t_free *new, t_free *tmp);
int			free_size(t_m_free *m_free);

#endif // GARBAGE_HPP
