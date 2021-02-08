/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:51:35 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/08 09:51:48 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALE_H
# define GLOBALE_H

#include "Rtv1.h"

# define WIN_H 1000
# define WIN_W 1000
////// Infinte distance, used as a default value
# define DIST_MAX 20000
//////// in order to prevent boucing rays self-intersecting
# define DIST_MIN 0.0001
# define FOV 30
# define KEY_ESC 53

#endif
