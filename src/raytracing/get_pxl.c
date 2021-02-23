/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:02:17 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/23 10:02:33 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector			get_pxl(t_rtv *rtv,t_ray ray)
{
	double			dst_min;
	t_object		*obj;
	t_vector		hit_point;
	t_vector		color;
	t_vector		normal;

	cord(&color,0,0,0);
	obj = NULL;
	if ((dst_min = get_dest(rtv,ray,&obj)) == 9999)
		return(color);
	hit_point = add(ray.origin , multi(ray.direction,dst_min));
	if (obj)
		color = colors(rtv, obj, hit_point, obj_normal(ray, obj, dst_min),ray);
	return (color);
}