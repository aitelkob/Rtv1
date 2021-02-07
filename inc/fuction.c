/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuction.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:22:35 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/07 15:17:20 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUCTION_H
# define FUCTION_H

#include "Rtv1.h"

/**
  ****************   parsing *****************
**/
void			parce(char *av,t_rtv *rtv);

void			plan_parce(t_rtv *rtv);
void			sphere_parce(t_rtv *rtv);
void			cylinder_parce(t_rtv *rtv);
void			cone_parce(t_rtv *rtv);
void			light_parce(t_rtv *rtv);
///////// string manipulation

char			*settings_cut(t_rtv *rtv,char *variable,char **data);
char			*name_cut(t_rtv *rtv,char *line);
void			forward(t_rtv   *rtv,char *line);
/////////////error 

void			syntax_error(char *line, char *reasoning, int nbline);
void			unknown_setting(char *line, int nbline);
void			error(char *str,char *where);
///////////// list manipulation

void            first_light(t_rtv *rtv, t_light *light);
void            first_obj(t_rtv *rtv, t_object *obj);
t_vector        input_vector(char *data,int nbr);
double          input_onearg(char *data,int nbr);

/**
 * ****************************** vector lib
**/

t_vector		add(t_vector vec1, t_vector vec2);
t_vector		sub(t_vector vec1, t_vector vec2);
t_vector		multi(t_vector vec1, double t);
t_vector		Div(t_vector vec1, double t);
double			length_squared(t_vector vec1, t_vector vec2);
double			length(t_vector vec1, t_vector vec2);
/**
 * ********************************* mlx stuff
**/ 
void			display(t_mlix *mlx);
int				key_hook(int keycode, t_mlix *mlix);
void			setup_mlx(t_mlix *mlx);
void			ft_destroy(t_mlix *mlx);
void            ft_put_pixel(t_mlix *mlx,int x ,int y,int color);

/**
 * ********************************* raytracing
**/ 
void            raytracing(t_rtv *rtv);
#endif
