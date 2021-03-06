/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:49:04 by yait-el-          #+#    #+#             */
/*   Updated: 2021/03/04 18:24:56 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//double get_dest(t_rtv *rtv, t_ray ray,t_object **close, t_object *current);

/*int color_nrm(int i)
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
}*/

t_vector		camera(t_camera *camera, int x, int y, t_vector up)
{
	t_ray		ray;
	t_vector	w_vector;
	t_vector	u_vector;
	t_vector	v_vector;
	t_vector	p;

	ray.origin = camera->origin;
	ray.direction = camera->look_at;
	ray.origin.x += 0.000000001;
	w_vector = nrm(sub(ray.direction, ray.origin));
	u_vector = nrm(crossproduct(w_vector, up));
	v_vector = crossproduct(w_vector, u_vector);
	p.z = tan(deg_to_rad(camera->fov) / 2) * 2;
	p.x = map(x, -1, ((1.0 - (-1.0)) / (WIN_W - 0.0)));
	p.y = map(y, -1, ((1.0 - (-1.0)) / (WIN_W - 0.0)));
	return (add(add(multi(u_vector, p.x * p.z)
	, multi(v_vector, p.y * p.z)), w_vector));
}

void				raytracing(t_rtv *rtv)
{
	int				x;
	int				y;
	t_vector		color;
	t_vector		up;
	t_ray			ray2;

	ray2.origin = rtv->camera->origin;
	up = (t_vector){0, 1, 0};
	x = -1;
	while (++x <= WIN_H)
	{
		y = -1;
		while (++y <= WIN_W)
		{
			ray2.direction = camera(rtv->camera, x, y, up);
			color = get_pxl(rtv, ray2);
			rtv->mlx.img[(WIN_H - 1 - y) * WIN_W + x] = rgb_to_int(color);
		}
	}
}
