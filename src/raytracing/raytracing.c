/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:49:04 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/12 18:33:24 by yait-el-         ###   ########.fr       */
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

/*double			intersection_sphere()
{
	double a,b,c,t0,t1,tmp;
	///// rays ba9i 5asni nefhamhom 
	t_vector x;
	x = vecto_subvec(ray.origin,sphere.origin);
	/////// calculate qudratic coefficients
	a = dot(ray.direction,ray.direction);
	b = 2 * dot(ray.direction,x);
	c = dot(x,x) - (sphere.radius * sphere.radius);

	////// check whether we intersect
	***  (-b±√(b²-4ac))
	 *     ---------------
	 *          (2a)
	 **
	////// check whether we intersect
	tmp = b * b - 4 * a * c;
	t0 = (-b + sqrt(tmp)) / (2 * a);
	t1 = (-b - sqrt(tmp)) / (2 * a);
	if (t0 > t1)
		return (t1);
	else
		return (t0);
}
*/
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
double			get_dest(t_ray *rtv,t_object *obj)
{
	t_object		*tmp;
	double			dst;

	tmp = rtv->obj;

	while (tmp)
	{
		if (tmp->type == SPHERE)
			///// dst = intersection of Sphere
		else if (tmp->type == PLANE)
			///// dst = intersection pf plane
		else if (tmp->type == CYLINDER)
			///// dst = intersection of cylinder
		else if (tmp->type == CONE)
			///// dst = intersection of cone
		tmp = tmp->next;
	}
}
void			raytracing(t_rtv *rtv)
{
	t_vec 
	int x;
	int y;
	unsigned int *img_temp;

	//jgjhg
	t_ray ray;
	cord(&ray.origin, 50, 50, 0);
	cord(&ray.direction, 50, 50, 50);
	//hna 
	

	x = -1;
	while (++x < WIN_H)
	{
		y = -1;
		while (++y < WIN_W)
		{


			///tekhrbihg diyal sofiane

			/*t_vector plane_vec_s;
			t_vector plane_org;
			t_vector up;
			
			cord(&up, 0, 1, 0);
			cord(&plane_vec_s, 0, 1, 0);
			cord(&plane_org, 50, 50, 100);
			
			
			t_vector plane_vec = Div(plane_vec_s,(length(plane_vec_s, plane_vec_s)));
			t_vector xvec = sub(ray.origin, plane_org);
			
			
			t_vector dirvecs_norm = camera(ray, x, y, up); 	
			
			double a = length_squared(dirvecs_norm, dirvecs_norm);
			double b = length_squared(dirvecs_norm, xvec) * 2;
			double c = length_squared(xvec, xvec) - 50*50;
			double delta = b * b - 4 * a * c;*/
			if (delta > 0)////7ad hena
				rtv->mlx.img[(WIN_H - 1 - x) * WIN_W + y]=rgb_to_int(ft_itvect(15,157,88));
		}
	}

}
