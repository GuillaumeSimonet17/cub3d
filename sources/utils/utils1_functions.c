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

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(t_data *data, const char *src)
{
	char	*new_str;
	size_t	len;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	new_str = (char *)ft_calloc(data, len + 1, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strcpy(new_str, src);
	return (new_str);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long		sign;
	long long		nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb != ((nb * 10 + (sign * (str[i] - '0'))) / 10))
			return ((int)((sign + 1) / 2 / -1));
		nb = nb * 10 + (str[i] - 48) * sign;
		i++;
	}
	return ((int)nb);
}

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((big == NULL || little == NULL))
		return (NULL);
	if (((unsigned char *)little)[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (ft_strncmp((char *)&big, (char *)little, ft_strlen \
			((char *)little))
				&& little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
