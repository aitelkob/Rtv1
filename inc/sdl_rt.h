/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:38:59 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/24 18:34:42 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_RT_H
# define SDL_RT_H

#include "Rtv1.h"


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

void        ft_destroy(t_mlix *mlx);
void        setup(t_mlix *mlx);
void        display(t_mlix *mlx);

#endif
