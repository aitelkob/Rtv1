/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 05:30:23 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/12 17:48:50 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n1;
	int		n2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (n1 + n2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
