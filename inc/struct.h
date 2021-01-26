/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:40:46 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/26 11:47:47 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "Rtv1.h"
#include "sdl_rt.h"

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


#endif
