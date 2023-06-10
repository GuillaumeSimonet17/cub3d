/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:38:56 by bgresse           #+#    #+#             */
/*   Updated: 2023/06/07 12:35:53 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	u;

	i = 0;
	u = (unsigned char)c;
	while (s[i])
	{
		if (u == ((char *)s)[i])
			return ((char *)s + i);
		i++;
	}
	if (u == ((char *)s)[i])
		return ((char *)s + i);
	return (NULL);
}
