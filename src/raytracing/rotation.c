/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:31:49 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/27 18:51:35 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double				deg_to_rad(double angle)
{
	return (angle * (PI / 180.0));
}

t_vector			rotation(t_vector v,t_vector  angle)
{
	t_vector		res_x;
	t_vector		res_y;
	t_vector		res_z;
	double			alpha;

	////////// On the X-axis
	alpha = deg_to_rad(angle.x);
	res_x.x =  v.x;
	res_x.y = v.y * cos(alpha) + v.z * sin(alpha);
	res_x.z = -v.y* sin(alpha) + v.z * cos(alpha);
	////////// On the Y-axis
	
	alpha = deg_to_rad(angle.y);
	res_y.x = res_x.x * cos(alpha) + res_x.z * sin(alpha);
	res_y.y = res_x.y;
	res_y.z = - res_x.x * sin(alpha) + res_x.z * cos(alpha);
	///////// On the Z-axis
	
	alpha = deg_to_rad(angle.z);
	res_z.x = res_y.x * cos(alpha) - (res_y.y * sin(alpha));
	res_z.y = -res_y.x *sin(alpha) + (res_y.y * cos(alpha)); 
	res_z.z = res_y.z;
	print_vect(res_z,"thi is ");
	return (res_z);
}
