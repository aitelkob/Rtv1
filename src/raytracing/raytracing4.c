/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:49:04 by yait-el-          #+#    #+#             */
/*   Updated: 2021/03/01 11:52:39 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double get_dest(t_rtv *rtv, t_ray ray,t_object **close, t_object *current);

int color_nrm(int i)
{
	return i > 255 ? 255 : i;
}

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
		post = dot(light_dir, normal) < 0 ? 0: dot(light_dir, normal);
		//printf("post == %f \n", post);
		alfa =  (!(dst != -1 || post < 0)) * post;
		alfa2 = (dst == -1) * dot(h, normal);
		color = add(color, multi(obj->color, 0.1+alfa * (tmp->intensity/100)));
		color = add(color, multi(one,(tmp->intensity/100) * (alfa)*255 * powf(alfa2 < 0 ? 0 : alfa2, 100)));
		tmp = tmp->next;
	}

	return (color);
}

t_vector		camera(t_camera *camera,int x, int y, t_vector up)
{
	t_ray ray;
	ray.origin = camera->origin;
	ray.direction = camera->look_at;
	t_vector w_vector = nrm(sub(ray.direction, ray.origin)); // get w vector
	t_vector u_vector = crossproduct(w_vector, up); // get u vector
	t_vector v_vector = crossproduct(w_vector, u_vector); // get v vector

	double alpha = camera->fov * ((22.0/7.0) / 180.0);
	double pw = tan(alpha);
	double ph = pw;
	double px = map(x, 0, WIN_W,-pw/2,pw/2);
	double py = map(y, 0, WIN_H,-ph/2,ph/2);

	t_vector sum = add(multi(u_vector,px * pw), multi(v_vector,py * ph));
	return add(sum, w_vector);
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
		m = dot(ray.direction, obj->normal) * dst + dot(xvec, obj->normal);
	if (obj->type != PLANE)
		p_c = add(xvec, multi(ray.direction, dst));
	tk = 1 + tan(alpha / 2) * tan(alpha / 2);
	if (obj && obj->type == SPHERE)
		normal = p_c;
	else if (obj && obj->type == PLANE)
		normal = multi(obj->normal, -1);
	else if (obj && obj->type == CYLINDER)
		normal = sub(p_c, multi(obj->normal, m));
	else if (obj && obj->type == CONE)
		normal = sub(p_c, multi(obj->normal, tk * m));//sub(p_c, multi(obj->normal, (1 + tk * tk) * m));
	if(dot(ray.direction, normal) > 0)
	 	normal = multi(normal, -1);
	return nrm(normal);
}

t_vector			get_pxl(t_rtv *rtv,t_ray ray)
{
	double		dst_min;
	int i = 0;
	t_object	*obj = NULL;
	t_vector	hit_point;
	t_vector		color;
	t_vector		normal;
	t_object *current = NULL;

	cord(&color,0,0,0);
	if ((dst_min = get_dest(rtv,ray,&obj,current)) < 0)
		return(color);
	hit_point = add(ray.origin , multi(ray.direction,dst_min));

	if (dst_min > 0)
		color = obj->color;
	if (rtv->light)
		color = colors(rtv, obj, hit_point, obj_normal(ray, obj, dst_min),ray);
	return (color);
}
double get_dest(t_rtv *rtv, t_ray ray,t_object **close, t_object *current)
{
	t_object *tmp;
	double dst;

	tmp = rtv->obj;
	double min = -1;
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
			if (dst > 0 && (dst < min  || min == -1))
			{
				*close = tmp;
				min = dst;
			}
		tmp = tmp->next;
	}
	if (current != NULL && *close == current)
		return(-1);
	return(min);
}
void			raytracing(t_rtv *rtv)
{ 
	printf("tesr = %d \n", 1 < 0);
	int x;
	int y;
	unsigned int *img_temp;
	t_vector		color;
	t_vector		up;

	//camera start
	t_ray ray2;

	ray2.origin = rtv->camera->origin;
	up =(t_vector){0,1,0};
	x = -1;
	while (++x <= WIN_H)
	{
		y = -1;
		while (++y <= WIN_W)
		{

			/////////////start here

			ray2.direction = camera(rtv->camera,x,y,up);
			//double dst = get_dest(rtv,ray2);
			color = get_pxl(rtv,ray2);
			//print_vect(color,"color");
			rtv->mlx.img[(WIN_H - 1 - y) * WIN_W + x]=rgb_to_int(color);

		}
	}

}
