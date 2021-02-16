/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:20:45 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/16 11:02:11 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

void cord(t_vector *vec, double x, double y, double z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

t_vector nrm(t_vector vec)
{
    return Div(vec, (length(vec, vec)));
}

t_vector        ft_itvect(int x,int y, int z)
{
    t_vector vex;

    vex.x = x;
    vex.y = y;
    vex.z = z;
    return (vex);
}

t_vector CrossProduct(t_vector vec1, t_vector vec2)
{
    t_vector result;

    result.x = vec1.y * vec2.z - vec2.y * vec1.z;
    result.y = vec1.x * vec2.z - vec2.x * vec1.z;
    result.z = vec1.x * vec2.y - vec2.x * vec1.y;

    return result;
}

t_vector        vecto_subvec(t_vector v1,t_vector v2)
{
    return (ft_itvect(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

double map(double x, double sw, double ew, double spw, double epw)
{
    return x * ((epw - spw) / (ew - sw)) + spw;
}

double      dot(t_vector v, t_vector b)
{
    return ((v.x * b.x) + (v.y * b.y) + (v.z * b.z));
}
