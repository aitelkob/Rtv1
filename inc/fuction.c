/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuction.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:22:35 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/01 19:00:18 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUCTION_H
# define FUCTION_H

#include "Rtv1.h"

//////////////// parsing
void        parce(char *av,t_rtv *rtv);
void        plan_parce(t_rtv *rtv);
void        sphere_parce(t_rtv *rtv);
char        *settings_cut(t_rtv *rtv,char *variable,char **data);
char        *name_cut(t_rtv *rtv,char *line);
void        forward(t_rtv   *rtv,char *line);
void    error(char *str,char *where);
////////////////// calc_vect.c
t_vector add(t_vector vec1, t_vector vec2);
t_vector sub(t_vector vec1, t_vector vec2);
t_vector multi(t_vector vec1, double t);
t_vector Div(t_vector vec1, double t);
double length_squared(t_vector vec1, t_vector vec2);
double length(t_vector vec1, t_vector vec2);

//////////
void    syntax_error(char *line, char *reasoning, int nbline);
void    unknown_setting(char *line, int nbline);
//////////// 
#endif
