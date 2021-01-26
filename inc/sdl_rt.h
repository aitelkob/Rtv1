/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:38:59 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/26 09:35:36 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_RT_H
# define SDL_RT_H

#include "Rtv1.h"
#include "struct.h"

void        ft_destroy(t_mlix *mlx);
void        setup(t_mlix *mlx);
void        display(t_mlix *mlx);

#endif
