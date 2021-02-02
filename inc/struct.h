/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:40:46 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/02 17:58:56 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "Rtv1.h"
#include "sdl_rt.h"

typedef	struct		s_vector
{
	double			x;
	double			y;
	double				z;
}					t_vector;

typedef	struct		s_ray
{
	t_vector		origin;
	t_vector		direction;
}					t_ray;

typedef	struct		s_parse
{
	int				fd;
	char			*line;
	int				nb_line;
	char			**agv;
	char			*obj_name;
}                 t_parse;

typedef struct      s_light
{
  double            intensity;
  t_vector          origin;
  struct s_light    *next;
}                   t_light;

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
	double			radius;
	t_vector		origin;
	t_vector		normal;
	t_vector		direction;
	t_vector		color;
	struct s_object	*next;
}					t_object;

typedef	struct		s_rtv
{
	t_mlix			mlx;
	t_object		*obj;
	t_parse			parse;
	t_light			*light;	
}					t_rtv;

#endif
