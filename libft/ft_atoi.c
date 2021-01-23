/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:03:22 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/22 03:58:30 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	reste;
	int	i;

	i = 0;
	reste = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		str++;
	if (*str == '-' || *str == '+')
		i = 1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		reste = (reste * 10) + (str[i] - '0');
		i++;
	}
	if (*str == '-')
		return (-reste);
	return (reste);
}
