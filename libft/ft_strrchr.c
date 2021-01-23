/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:59:00 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/22 03:52:31 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = (int)ft_strlen(str);
	if ((unsigned char)c == '\0')
		return ((char*)(str + i));
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char*)(str + i));
		i--;
	}
	return (NULL);
}
