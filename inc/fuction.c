/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuction.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:22:35 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/15 17:03:31 by yait-el-         ###   ########.fr       */
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
void			camera_parce(t_rtv *rtv);
///////// string manipulation

char			*settings_cut(t_rtv *rtv,char *variable,char **data);
char			*name_cut(t_rtv *rtv,char *line);
void			forward(t_rtv   *rtv,char *line);
/////////////error 

void			syntax_error(char *line, char *reasoning, int nbline);
void			unknown_setting(char *line, int nbline);
void			error(char *str,char *where);
///////////// list manipulation
void            first_camera(t_rtv *rtv, t_camera *camera);
void            first_light(t_rtv *rtv, t_light *light);
void            first_obj(t_rtv *rtv, t_object *obj);
t_vector        input_vector(char *data,int nbr);
double          input_onearg(char *data,int nbr);

/**
 * ****************************** vector lib
 **/
void            print_vect(t_vector vec,char *str);
t_vector		add(t_vector vec1, t_vector vec2);
t_vector		sub(t_vector vec1, t_vector vec2);
t_vector		multi(t_vector vec1, double t);
t_vector		normalize(t_vector vector);
t_vector		Div(t_vector vec1, double t);
double			length_squared(t_vector vec1, t_vector vec2);
double			length(t_vector vec1, t_vector vec2);
void cord(t_vector *vec, double x, double y, double z);
t_vector		ft_itvect(int x,int y, int z);
t_vector		vecto_subvec(t_vector v1,t_vector v2);
double			dot(t_vector v, t_vector b);
double			map(double x, double sw, double ew, double spw, double epw);
t_vector CrossProduct(t_vector vec1, t_vector vec2);
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
double          intersection_plane(t_ray ray, t_object plane);
double			intersection_cylinder(t_ray ray, t_object cylinder);
double			intersection_cone(t_ray ray, t_object cone);
double          intersection_sphere(t_ray ray,t_object sphere);

/**
 * ******************************** to del
 **/ 
void            print_vect(t_vector vec,char *str);
#endif
