/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:20:45 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/15 17:14:42 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

static double     quadratic(double a, double b, double c)
{
    double      determinant;
    double      t0;
    double      t1;

      ////// check whether we intersect
      /***  (-b±√(b²-4ac))sss
       *     ---------------
       *          (2a)
       **/
     ////// check whether we intersect
    determinant = b * b - 4 * a * c;
    if (determinant < 0)
        return (-1);
    if (determinant == 0)
        return (-b / (2 * a));
    t0 = (-b + sqrt(determinant)) / (2 * a);
    t1 = (-b - sqrt(determinant)) / (2 * a);
    return (t0 > t1) ? t1 : t0;
}

double          intersection_plane(t_ray ray, t_object plane)
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
}

double intersection_cylinder(t_ray ray, t_object cylinder)
{
    double a, b, c, t0, t1, tmp;

    t_vector x;
    x = vecto_subvec(ray.origin, cylinder.origin);
    /////// calculate qudratic coefficients

    a = dot(ray.direction, ray.direction) - dot(ray.direction, cylinder.normal) * dot(ray.direction, cylinder.normal);
    b = (dot(ray.direction, x) - dot(ray.direction, cylinder.normal) * dot(x,cylinder.normal)) * 2;
    c = dot(x, x) - dot(x, cylinder.normal) * dot(x, cylinder.normal) - cylinder.radius * cylinder.radius;
     return (quadratic(a,b,c));
}

double intersection_cone(t_ray ray, t_object cone)
{
    double a, b, c, t0, t1, tmp, alpha, tk;

    t_vector x;
    alpha = 60 * ((22.0 / 7.0) / 180.0);
    x = vecto_subvec(ray.origin, cone.origin);
    /////// calculate qudratic coefficients
    a = dot(ray.direction, ray.direction);
    b = 2 * dot(ray.direction, x);
    c = dot(x, x) - (cone.radius * cone.radius);

    tk = 1 + tan(alpha / 2) * tan(alpha / 2);
    a = dot(ray.direction, ray.direction) - tk * dot(ray.direction, cone.normal) * dot(ray.direction, cone.normal);
    b = (dot(ray.direction, x) - tk * dot(ray.direction, cone.normal) * dot(x, cone.normal)) * 2;
    c = dot(x, x) - tk * dot(x, cone.normal) * dot(x, cone.normal);
     return (quadratic(a,b,c));
}

double          intersection_sphere(t_ray ray,t_object sphere)
{
    double a,b,c,t0,t1,tmp;

    t_vector x;
    x = vecto_subvec(ray.origin,sphere.origin);
    /////// calculate qudratic coefficients
    a = dot(ray.direction,ray.direction);
    b = 2 * dot(ray.direction,x);
    c = dot(x,x) - (sphere.radius * sphere.radius);
     return (quadratic(a,b,c));
}
