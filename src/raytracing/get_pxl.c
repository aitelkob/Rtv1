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

t_vector			colors(t_rtv *rtv,t_object *obj,t_vector hit, t_vector aim, t_ray ray);
t_vector			obj_norm(t_ray ray, t_object *obj, double dst)
{
	double			m;
	double			tk;
	t_vector		normal;
	t_vector		p_c;
	t_vector		xvec;

	xvec = vecto_subvec(ray.origin, obj->origin);
	if (obj->type != PLANE && obj->type != SPHERE)
		m = dot(ray.direction, obj->aim) * dst + dot(xvec, obj->aim);
	if (obj->type != PLANE)
		p_c = add(xvec, multi(ray.direction, dst));
	tk = 1 + tan(deg_to_rad(60) / 2) * tan(deg_to_rad(60) / 2);
	if (obj && obj->type == SPHERE)
		normal = p_c;
	else if (obj && obj->type == PLANE)
		normal = multi(obj->aim, -1);
	else if (obj && obj->type == CYLINDER)
		normal = sub(p_c, multi(obj->aim, m));
	else if (obj && obj->type == CONE)
		normal = sub(p_c, multi(obj->aim, tk * m));
	if (dot(ray.direction, normal) > 0)
		normal = multi(normal, -1);
	return (nrm(normal));
}

t_vector			get_pxl(t_rtv *rtv, t_ray ray)
{
	double			dst_min;
	int				i;
	t_object		*obj = NULL;
	t_vector		hit_point;
	t_vector		color;
	t_vector		aim;
	t_object		*current = NULL;

	color = (t_vector){0, 0, 0};
	if ((dst_min = get_dest(rtv, ray, &obj, current)) < 0)
		return(color);
	hit_point = add(ray.origin, multi(ray.direction, dst_min));
	if (dst_min > 0)
		color = obj->color;
	if (rtv->light)
		color = colors(rtv, obj, hit_point, obj_norm(ray, obj, dst_min), ray);
	return (color);
}
