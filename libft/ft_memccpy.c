/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 04:00:32 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/21 17:59:06 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	c1 = (unsigned char)c;
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == c1)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
