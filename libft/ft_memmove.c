/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:08:46 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/22 03:55:16 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;

	temp = NULL;
	if (dest < src || dest > (src + n))
		ft_memcpy(dest, src, n);
	else
	{
		if (!(temp = (unsigned char *)malloc(n * sizeof(unsigned char))))
			return (0);
		else
		{
			ft_memcpy(temp, src, n);
			ft_memcpy(dest, temp, n);
			free(temp);
		}
		temp = NULL;
	}
	return (dest);
}
