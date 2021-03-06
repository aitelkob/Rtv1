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

int color_nrm(int i)
{
	return i > 255 ? 255 : i;
}

int					rgb_to_int(t_vector v)
{
	int				red;
	int				green;
	int				blue;
	int				rgb;

	red = color_nrm((int)v.x);
	green = color_nrm((int)v.y);
	blue = color_nrm((int)v.z);
	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}


double shadow(t_light *tmp_light, t_vector light_dir, t_rtv *rtv, t_object *obj)
{
	t_ray ray_light;
	t_object *tmp_obj;

	ray_light.origin =  tmp_light->origin;
	ray_light.direction = nrm(multi(light_dir, -1));
	return get_dest(rtv, ray_light, &tmp_obj, obj);
}

double specular(t_vector org_hit, t_vector light_dir, double dst, t_vector normal)
{
	t_vector cam_light;

	cam_light = nrm(add(light_dir, org_hit));
	return (dst == -1) * dot(cam_light, normal);
}

double diffuse(t_vector light_dir, double dst, t_vector normal)
{
	double alpha;
	alpha = dot(light_dir, normal) < 0 ? 0: dot(light_dir, normal);
	return (!(dst != -1 || alpha < 0)) * alpha;
}

t_vector coloring(double diffuse, double specular, t_vector obj_color)
{
	t_vector color;
	
	color =(t_vector) {0,0,0};
	color = add(color, multi(obj_color, 0.1 + diffuse));
	color = add(color, multi((t_vector) {1,1,1},
	diffuse * 255 *powf(specular < 0 ? 0 : specular, 100)));
	return color;
}

t_vector			lighting(t_rtv *rtv,t_object *obj,t_vector hit, t_vector normal, t_ray ray)
{
	t_light *tmp;
	t_vector light_dir;
	t_vector color;
	double dst;
	double spec;
	
	tmp = rtv->light;
	
	while (tmp)
	{
		light_dir = nrm(sub(tmp->origin, hit));

		dst = shadow(tmp, light_dir, rtv, obj);

		spec = specular(sub(ray.origin,hit), light_dir, dst, normal);

		color = coloring(diffuse(light_dir, dst, normal) \
				* (tmp->intensity / 100.0), spec, obj->color);
		
		tmp = tmp->next;
	}

	return (color);
}