/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:32:44 by mzaboub           #+#    #+#             */
/*   Updated: 2019/05/07 14:52:49 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_isprime(size_t nb)
{
	size_t	i;
	size_t	compt;

	i = 1;
	compt = 1;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
		{
			compt++;
			if (compt > 2)
				return (0);
		}
		i++;
	}
	if (compt == 2)
		return (1);
	else
		return (0);
}
