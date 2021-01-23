/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:56:01 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/01 02:18:16 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	int		n;

	i = 0;
	n = ft_strlen(s);
	str = (char*)malloc((n + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
	{
		while (i < n)
		{
			str[i] = s[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
