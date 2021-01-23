/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:41:31 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/21 18:06:50 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(str);
	if ((char)c == '\0')
		return (char*)(str + slen);
	while (i < slen)
	{
		if (str[i] == (char)c)
			return ((char*)(str + i));
		else
			i++;
	}
	return (NULL);
}
