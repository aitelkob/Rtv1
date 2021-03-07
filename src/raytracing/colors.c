/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:15:32 by yait-el-          #+#    #+#             */
/*   Updated: 2021/03/04 19:15:36 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double				shadow(t_light *tmp_light, t_vector light_dir,
t_rtv *rtv, t_object *obj)
{
	t_ray			ray_light;
	t_object		*tmp_obj;

	ray_light.origin = tmp_light->origin;
	ray_light.direction = nrm(multi(light_dir, -1));
	return (get_dest(rtv, ray_light, &tmp_obj, obj));
}

double				specular(t_vector org_hit, t_vector light_dir,
double dst, t_vector normal)
{
	t_vector		cam_light;

	cam_light = nrm(add(light_dir, org_hit));
	return (dst == -1) * dot(cam_light, normal);
}

double				diffuse(t_vector light_dir, double dst, t_vector normal)
{
	double			alpha;

	alpha = dot(nrm(light_dir), normal);
	return ((!(dst != -1 || alpha < 0)) * alpha);
}

t_vector			coloring(t_vector color, double diffuse,
double specular, t_vector obj_color)
{
	color = add(color, multi(obj_color, 0.1 + diffuse));
	color = add(color, multi((t_vector) {1, 1, 1},
	diffuse * 255 * powf(specular < 0 ? 0 : specular, 100)));
	return (color);
}

t_vector			lighting(t_rtv *rtv, t_object *obj, t_vector hit, t_ray ray)
{
	t_light			*tmp;
	t_vector		light_dir;
	t_vector		color;
	double			dst;
	double			spec;

	tmp = rtv->light;
	color = (t_vector) {0, 0, 0};
	while (tmp)
	{
		light_dir = sub(tmp->origin, hit);
		dst = shadow(tmp, light_dir, rtv, obj);
		spec = specular(sub(ray.origin, hit), light_dir, dst, obj->normal);
		color = coloring(color, diffuse(light_dir, dst, obj->normal) \
		* (tmp->intensity / 100.0), spec, obj->color);
		tmp = tmp->next;
	}
	return (color);
}
