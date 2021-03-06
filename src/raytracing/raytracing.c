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

t_vector			camera(t_camera *camera, int x, int y, t_vector up)
{
	t_ray			ray;
	t_vector		w_vector;
	t_vector		u_vector;
	t_vector		v_vector;
	t_vector		p;

	ray.origin = camera->origin;
	ray.direction = camera->look_at;
	ray.origin.x += 0.000000001;
	w_vector = nrm(sub(ray.direction, ray.origin));
	u_vector = nrm(crossproduct(w_vector, up));
	v_vector = crossproduct(w_vector, u_vector);
	p.z = tan(deg_to_rad(camera->fov) / 2.0);
	p.x = map(x, -1, ((1.0 - (-1.0)) / (WIN_W - 0.0)));
	p.y = map(y, 1, ((-1.0 - (1.0)) / (WIN_W - 0.0)));
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
	while (++x < WIN_H)
	{
		y = -1;
		while (++y < WIN_W)
		{
			ray2.direction = nrm(camera(rtv->camera, x, y, up));
			color = get_pxl(rtv, ray2);
			rtv->mlx.img[(WIN_H - 1 - y) * WIN_W + x] = rgb_to_int(color);
		}
	}
}
