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

t_vector			colors(t_rtv *rtv,t_object *obj,t_vector hit, t_vector aim, t_ray ray)
{
	//t_ray ray;
	//t_object   *tmp;
	double  dist_light;
	double   dist;
	double intensity;
	t_light *tmp;
	t_vector color;
	double alfa;
	double alfa2;
	double dst;
	t_object *tmp2;
	t_vector h;
	t_vector one;
	t_vector light_dir;
	t_ray ray2;
	double post;
	intensity = 0;
	tmp = rtv->light;
	cord(&one,1,1,1);
	color =(t_vector) {0,0,0};
	while (tmp)
	{
		light_dir = nrm(sub(tmp->origin, hit));
		dist_light = length(light_dir,light_dir);
		ray2.origin =  tmp->origin;
		ray2.direction = nrm(multi(light_dir, -1));
		dst = get_dest(rtv,ray2,&tmp2,obj);
		h = nrm(add(light_dir,sub(ray.origin,hit)));
		post = dot(light_dir, aim) < 0 ? 0: dot(light_dir, aim);
		//printf("post == %f \n", post);
		alfa =  (!(dst != -1 || post < 0)) * post;
		alfa2 = (dst == -1) * dot(h, aim);
		color = add(color, multi(obj->color, 0.1+alfa * (tmp->intensity/100)));
		color = add(color, multi(one,(tmp->intensity/100) * (alfa)*255 * powf(alfa2 < 0 ? 0 : alfa2, 100)));
		tmp = tmp->next;
	}

	return (color);
}