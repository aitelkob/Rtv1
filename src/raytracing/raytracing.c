/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:49:04 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/07 17:57:58 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

t_vector		ft_itvect(int x,int y, int z)
{
	t_vector vex;

	vex.x = x;
	vex.y = y;
	vex.z = z;
	return (vex);
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

double			intersection()
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
/***  (-b±√(b²-4ac))
*     ---------------
*          (2a)
**/
	////// check whether we intersect
	tmp = b * b - 4 * a * c;
	t0 = (-b + sqrt(tmp)) / (2 * a);
	t1 = (-b - sqrt(tmp)) / (2 * a);
		if (t0 > t1)
			return (t1);
		else
			return (t0);
}

void			raytracing(t_rtv *rtv)
{
	int i;
	int y;
	unsigned int *img_temp;


	i = -1;
	while (++i < WIN_H)
	{
		y = -1;
		while (++y < WIN_W)
		{
			if ()
			 rtv->mlx.img[(WIN_H - 1 - i) * WIN_W + y]=rgb_to_int(ft_itvect(15,157,88));
		}
	}

}
