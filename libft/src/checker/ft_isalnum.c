/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:07:36 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 10:07:37 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c <= '9' && c >= '0') || (c <= 'z' && c >= 'a') ||
			(c <= 'Z' && c >= 'A'))
		return (1);
	else
		return (0);
}
