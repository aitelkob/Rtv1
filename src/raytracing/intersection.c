/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:20:45 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/19 12:12:09 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	double			quadratic(double a, double b, double c)
{
	double				determinant;
	double				t0;
	double				t1;

	determinant = b * b - 4 * a * c;
	if (determinant < 0)
		return (-1);
	if (determinant == 0)
		return (-b / (2 * a));
	t0 = (-b + sqrt(determinant)) / (2 * a);
	t1 = (-b - sqrt(determinant)) / (2 * a);
	return (t0 > t1) ? t1 : t0;
}

double					intersection_plane(t_ray ray, t_object plane)
{
	double				d;
	double				dist;
	t_vector			vector_distance;

	d = dot(plane.normal, ray.direction);
	if (d > DIST_MIN)
	{
		vector_distance = vecto_subvec(plane.origin, ray.origin);
		dist = dot(vector_distance, plane.normal) / d;
		return (dist);
	}
	return (DIST_MAX);
}

double					intersection_cylinder(t_ray ray, t_object cylinder)
{
	t_inters			inter;

	inter.x = vecto_subvec(ray.origin, cylinder.origin);
	inter.a = dot(ray.direction, ray.direction) - dot(ray.direction,
			cylinder.normal) * dot(ray.direction, cylinder.normal);
	inter.b = (dot(ray.direction, inter.x) - dot(ray.direction,
				cylinder.normal) * dot(inter.x, cylinder.normal)) * 2;
	inter.c = dot(inter.x, inter.x) - dot(inter.x, cylinder.normal) *
		dot(inter.x, cylinder.normal) - cylinder.radius * cylinder.radius;
	return (quadratic(inter.a, inter.b, inter.c));
}

double					intersection_cone(t_ray ray, t_object cone)
{
	double				alpha;
	double				tk;
	t_inters			inter;

	alpha = 60 * ((22.0 / 7.0) / 180.0);
	inter.x = vecto_subvec(ray.origin, cone.origin);
	inter.a = dot(ray.direction, ray.direction);
	inter.b = 2 * dot(ray.direction, inter.x);
	inter.c = dot(inter.x, inter.x) - (cone.radius * cone.radius);
	tk = 1 + tan(alpha / 2) * tan(alpha / 2);
	inter.a = dot(ray.direction, ray.direction) - tk * dot(ray.direction,
			cone.normal) * dot(ray.direction, cone.normal);
	inter.b = (dot(ray.direction, inter.x) - tk * dot(ray.direction,
				cone.normal) * dot(inter.x, cone.normal)) * 2;
	inter.c = dot(inter.x, inter.x) - tk * dot(inter.x,
			cone.normal) * dot(inter.x, cone.normal);
	return (quadratic(inter.a, inter.b, inter.c));
}

double					intersection_sphere(t_ray ray, t_object sphere)
{
	t_inters			inter;

	inter.x = vecto_subvec(ray.origin, sphere.origin);
	inter.a = dot(ray.direction, ray.direction);
	inter.b = 2 * dot(ray.direction, inter.x);
	inter.c = dot(inter.x, inter.x) - (sphere.radius * sphere.radius);
	return (quadratic(inter.a, inter.b, inter.c));
}
