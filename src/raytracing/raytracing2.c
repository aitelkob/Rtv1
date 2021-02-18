/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:56:33 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/10 18:13:15 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"
t_vector        camera(t_ray    *ray, int x, int y, t_vector up,t_rtv *rtv)
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

void		raytracing(t_rtv *rtv)
{
	int x;
 	int y;
	int color;

		 x = -1;
	 while (++x < WIN_H)
	 {
    	 y = -1;
    	 while (++y < WIN_W)
    	 {


			 color = render();
		 }
	}
}
