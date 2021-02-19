/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:06:01 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/19 15:08:24 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector		vecto_subvec(t_vector v1, t_vector v2)
{
	return (ft_itvect(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

double			map(double x, double sw, double ew, double spw, double epw)
{
	return (x * ((epw - spw) / (ew - sw)) + spw);
}

double			dot(t_vector v, t_vector b)
{
	return ((v.x * b.x) + (v.y * b.y) + (v.z * b.z));
}
