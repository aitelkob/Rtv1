/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 05:12:38 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/21 23:54:48 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		ft_memset(str, '\0', size + 1);
	return (str);
}
