/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:53:29 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/21 17:35:30 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char*)(str));
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (to_find[j] != '\0')
		{
			if (str[i + j] != to_find[j] || i + j >= n)
				break ;
			j++;
		}
		if (to_find[j] == '\0')
			return ((char*)(str + i));
		i++;
	}
	return (NULL);
}
