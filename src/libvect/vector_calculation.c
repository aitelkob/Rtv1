/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:20:45 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/19 15:11:55 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			cord(t_vector *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

double			length(t_vector vec1, t_vector vec2)
{
	double		result;
	result = sqrt(length_squared(vec1, vec2));
	return (result);
}

t_vector		nrm(t_vector vec)
{
	return (divi(vec, (length(vec, vec))));
}

t_vector		ft_itvect(int x, int y, int z)
{
	t_vector	vex;

	vex.x = x;
	vex.y = y;
	vex.z = z;
	return (vex);
}

t_vector		crossproduct(t_vector vec1, t_vector vec2)
{
	t_vector	result;

	result.x = vec1.y * vec2.z - vec2.y * vec1.z;
	result.y = vec2.x * vec1.z - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec2.x * vec1.y;
	return (result);
}
