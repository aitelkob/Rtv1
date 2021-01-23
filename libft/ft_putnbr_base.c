/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:33:17 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/23 02:04:28 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j + 1])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_putnbr_base(int nb, char *base)
{
	int	a;
	int	len_base;

	len_base = ft_strlen(base);
	if (len_base < 2)
		return ;
	if (check_base(base) != 1)
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	a = nb % len_base;
	nb = nb / len_base;
	if (nb > 0)
		ft_putnbr_base(nb, base);
	ft_putchar(base[a]);
}
