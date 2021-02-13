/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:49:04 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/13 15:49:40 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"
void cord(t_vector *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}


t_vector		ft_itvect(int x,int y, int z)
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

double      dot(t_vector v, t_vector b)
{
	return ((v.x * b.x) + (v.y * b.y) + (v.z * b.z));
}

int             rgb_to_int(t_vector v)
{
	int         red;
	int         green;
	int         blue;
	int         rgb;

	red = (int)v.x;
	green = (int)v.y;
	blue = (int)v.z;
	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;

	return (rgb);
}

double map(double x, double sw, double ew, double spw, double epw)
{
    return x * ((epw - spw) / (ew - sw)) + spw;
}
/*
double			intersection_plane(t_object plane,t_)
{
	double      d;
	double      dist;
	t_vector    vector_distance;

	//// first , check if we intersect
	d = dot(plane.normal, ray.direction);
	/////check if it's less than the the minimum allowed
	/// otherwise it's outside the range we're
	if (d > DIST_MIN)
	{
		vector_distance =  vecto_subvec(plane.origin, ray.origin);
		dist = dot(vector_distance, plane.normal) / d;
		return (dist);
	}
	return (DIST_MAX);	
}*/

double			intersection_sphere(t_vector x,t_vector xvec,t_object *sphere)
{
	double a,b,c,t0,t1,tmp;
	///// rays ba9i 5asni nefhamhom 
	//t_vector x;
	//print_vect(ray.origin,"-->vector");
	//x = vecto_subvec(ray.origin,sphere->origin);
	/////// calculate qudratic coefficients
	 a = dot(x , x);
	 b = dot(x, xvec) * 2;
 	 c = dot(xvec, xvec) - (sphere->radius * sphere->radius);

	/*a = dot(ray.direction,ray.direction);
	b = 2 * dot(ray.direction,camera);
	c = dot(x,x) - (sphere->radius * sphere->radius);*/

	/*////// check whether we intersect
	  *****  (-b±√(b²-4ac))
	  **     ---------------
	  **          (2a)
	*/
	////// check whether we intersect
	tmp = b * b - 4 * a * c;
	return (tmp);
	/**t0 = (-b + sqrt(tmp)) / (2 * a);
	t1 = (-b - sqrt(tmp)) / (2 * a);
	if (t0 > t1)
		return (t1);
	else
		return (t0);*/
}

t_vector		camera(t_ray	*ray, int x, int y, t_vector up,t_rtv *rtv)
{

	t_vector dirvec = sub(ray->direction, ray->origin); // get w vector
	t_vector dirvec_norm = Div(dirvec,(length(dirvec, dirvec))); //normlize direction vec
	
	t_vector u_vector = CrossProduct(dirvec_norm, up); // get u vector
	t_vector v_vector = CrossProduct(dirvec_norm, u_vector); // get v vector
	
	//print_vect(ray->origin,"ray.origin");
	double alpha = 60 * ((22.0/7.0) / 180.0);
	double pw = tan(alpha);
	double ph = pw;
	double px = map(x, 0, WIN_W,-1,1);
	double py = map(y, 0, WIN_H,-1,1);

	t_vector sum = add(multi(u_vector,px * pw), multi(v_vector,py * ph));         
	return add(sum, dirvec_norm);
}
/*
double			intersect(t_rtv *rtv,t_vector camera,t_rtv xvec)
{
	t_object *current = rtv->obj;
	double	ret_sphere;
	double	ret_plane;

	while (current)
	{
		 if (current->type == SPHERE)
			 ret_sphere =  intersection_sphere(camera,xvec,current); 
		* else if (current->type == PLANE)
			 ret_plane =  intersection_plane(rtv->test,current);*
		current = current->next; 
	}
	if (ret_sphere)
		return ret_sphere;
	else if (ret_plane)
		return ret_plane;
	else 
		return 0;
}
*/
t_vector		get_origin(t_rtv *rtv)
{

	 t_object *current = rtv->obj;
	 t_vector rt;

	 cord(&rt,0,0,0);
	  while (current)
 	 {
       if (current->type == SPHERE)
          rt = current->origin;
	   current = current->next;
	 }
  return (rt);
}
void			raytracing(t_rtv *rtv)
{
	int x;
	int y;
	unsigned int *img_temp;

	//jgjhg
	t_ray ray;
	//cord(&ray.origin, 50, 50, 0);
	//cord(&ray.direction, 50, 50, 50);
	//hna i
	ray.origin = rtv->camera->origin;
	ray.direction = rtv->camera->look_at;

//	print_vect(ray.origin,"ray.origin");
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
			
			cord(&up, 0, 1, 0);
			cord(&plane_vec_s, 0, 1, 0);
			cord(&plane_org, 50, 50, 100);
			t_vector rere = get_origin(rtv);
			t_vector plane_vec = Div(plane_vec_s,(length(plane_vec_s, plane_vec_s)));

			
			t_vector xvec = sub(ray.origin, rere);	
			t_vector dirvecs_norm = camera(&ray, x, y, up,rtv);
			 
			double a = dot(dirvecs_norm, dirvecs_norm);
			double b = dot(dirvecs_norm, xvec) * 2;
			double c = dot(xvec, xvec) - 60*60;
			double delta = b * b - 4 * a * c;
			if (delta > 0)////7ad hena
				rtv->mlx.img[(WIN_H - 1 - x) * WIN_W + y]=rgb_to_int(ft_itvect(15,157,88));
		}
	}

}
