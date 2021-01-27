/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:40:46 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/27 19:21:13 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "Rtv1.h"
#include "sdl_rt.h"

typedef	struct		s_vector
{
	int				x;
	int				y;
	int				z;
}					t_vector;

typedef	struct		s_ray
{
	t_vector		origin;
	t_vector		direction;
}					t_ray;

typedef struct      s_mlix
{
    void            *mlx_ptr;
    void            *win_ptr;
    void            *img_ptr;
    int             *img;
    int             bits_per_pixel;
    int             size_line;
    int             endian;
}                   t_mlix;

typedef	struct		s_object
{
	char			*type;
	t_vector		radius;
	t_vector		origin;
	t_vector		direction;
	t_vector		color;
	struct s_object	*next;
}					t_object;

typedef	struct		s_rtv
{
	t_mlix			mlx;
	t_object		obj;
		
}					t_rtv;

#endif
