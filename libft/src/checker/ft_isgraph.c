/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:06:30 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 10:06:31 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isgraph(int c)
{
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 126))
		return (1);
	if ((char)c >= 48 && (char)c <= 57)
		return (1);
	else
		return (0);
}
