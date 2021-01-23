/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:15:33 by mzaboub           #+#    #+#             */
/*   Updated: 2019/05/07 14:53:47 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sqrt(size_t nb)
{
	size_t	sqr;
	size_t	temp;

	temp = nb / 4;
	if (temp <= 46340 && temp * temp <= nb)
		sqr = temp;
	else
		sqr = 1;
	while (sqr <= nb / 2)
	{
		if (sqr * sqr == nb)
			return (sqr);
		sqr++;
	}
	return (0);
}
