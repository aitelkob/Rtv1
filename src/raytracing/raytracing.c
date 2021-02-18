/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:49:04 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/18 16:29:45 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"
int color_nrm(int i)
{
	return i > 255 ? 255 : i;
}
double get_dest(t_rtv *rtv, t_ray ray,t_object **close);
int             rgb_to_int(t_vector v)
{
	int         red;
	int         green;
	int         blue;
	int         rgb;

	red = color_nrm((int)v.x);
	green = color_nrm((int)v.y);
	blue = color_nrm((int)v.z);
	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;

	return (rgb);
}

t_vector			colors(t_rtv *rtv,t_object *obj,t_vector hit, t_vector normal, t_ray ray)
{
	double intensity;
	t_light *tmp;
	t_vector color;
	double alfa;
	double alfa2;
	t_vector h;
	t_vector one;
	t_vector light_dir;
	intensity = 0;
	tmp = rtv->light;
	cord(&one,1,1,1);
	while (tmp)
	{
		light_dir = sub(tmp->origin, hit);
		h = nrm(add(light_dir,sub(ray.origin,hit)));
		alfa =  dot(light_dir, normal) / (length(light_dir, light_dir) * length(normal, normal));
		alfa2 = dot(h, normal) / (length(h, h) * length(normal, normal));
		color = add(color, multi(obj->color, fabs(alfa < 0 ? 0 : alfa)));
		color = add(color, multi(one,255 * powf(alfa2 < 0 ? 0 : alfa2, 10)));
		tmp = tmp->next;	
	}

	return (color);
}

t_vector		camera(t_ray ray, int x, int y, t_vector up)
{

	t_vector dirvec = sub(ray.direction, ray.origin); // get w vector
	t_vector dirvec_norm = Div(dirvec,(length(dirvec, dirvec))); //normlize direction vec

	t_vector u_vector = CrossProduct(dirvec_norm, up); // get u vector
	t_vector v_vector = CrossProduct(dirvec_norm, u_vector); // get v vector

	double alpha = 60 * ((22.0/7.0) / 180.0);
	double pw = tan(alpha);
	double ph = pw;
	double px = map(x, 0, WIN_W,-1,1);
	double py = map(y, 0, WIN_H,-1,1);

	t_vector sum = add(multi(u_vector,px * pw), multi(v_vector,py * ph));
	return add(sum, dirvec_norm);
}
t_vector obj_normal(t_ray ray, t_object *obj, double dst)
{
	t_vector xvec;
	double m;
	double tk;
	t_vector normal;
	t_vector p_c;
	double alpha;

	xvec = vecto_subvec(ray.origin, obj->origin);
	alpha = 60 * ((22.0 / 7.0) / 180.0);
	if (obj->type != PLANE && obj->type != SPHERE)
		m = dot(obj->direction, obj->normal) * dst + dot(xvec, obj->normal);
	if (obj->type != PLANE)
		p_c = add(xvec, multi(ray.direction, dst));
	tk = 1 + tan(alpha / 2) * tan(alpha / 2);
	if (obj && obj->type == SPHERE)
		normal = p_c;
	else if (obj && obj->type == PLANE)
		normal = multi(obj->normal, -1);
	else if (obj && obj->type == CYLINDER)
		normal = nrm(sub(p_c, multi(obj->normal, m)));
	else if (obj && obj->type == CONE)
		normal = sub(p_c, multi(obj->normal, (1 + tk * tk) * m));
	return normal;
}

t_vector			get_pxl(t_rtv *rtv,t_ray ray)
{
	double		dst_min;
	int i = 0;
	t_object	*obj = NULL;
	t_vector	hit_point;
	t_vector		color;
	t_vector		normal;

	cord(&color,0,0,0);
	if ((dst_min = get_dest(rtv,ray,&obj)) == -1)
		return(color);
	hit_point = add(ray.origin , multi(ray.direction,dst_min));
	if (obj)
		color = colors(rtv, obj, hit_point, obj_normal(ray, obj, dst_min),ray);
	return (color);
}
double get_dest(t_rtv *rtv, t_ray ray,t_object **close)
{
	t_object *tmp;
	double dst;

	tmp = rtv->obj;
	double min = 9999;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			dst = intersection_sphere(ray, *tmp);
		else if (tmp->type == PLANE)
			dst = intersection_plane(ray, *tmp);
		else if (tmp->type == CYLINDER)
			dst = intersection_cylinder(ray, *tmp);
		else if (tmp->type == CONE)
			dst = intersection_cone(ray, *tmp);
		if (dst < min)
		{
			min = (dst < 0) ? min : dst;
			*close = tmp;
		}
		tmp = tmp->next;
	}
	if (min < DIST_MAX)
		return(min);
	else
		return (-1);
}
void			raytracing(t_rtv *rtv)
{ 
	int x;
	int y;
	unsigned int *img_temp;
	t_vector		color;

	//camera start
	t_ray ray;
	t_ray ray2;
	ray.origin = rtv->camera->origin;
	ray.direction = rtv->camera->look_at;
	ray2.origin = ray.origin;

	x = -1;
	while (++x < WIN_H)
	{
		y = -1;
		while (++y < WIN_W)
		{
			///tekhrbihg diyal sofiane

			t_vector plane_vec_s;
			t_vector plane_org;
			t_vector up;
			//print_vect(rtv->light->origin,"light");
			cord(&up, 0, 1, 0);
			cord(&plane_vec_s, 0, 1, 0);
			cord(&plane_org, 50, 50, 100);
			/////////////start here
			ray2.direction = camera(ray,x,y,up);
			//double dst = get_dest(rtv,ray2);
			color = get_pxl(rtv,ray2);
			//print_vect(color,"color");
			rtv->mlx.img[(WIN_H - 1 - x) * WIN_W + y]=rgb_to_int(color);

		}
	}

}
