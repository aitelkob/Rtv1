/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:07:15 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/19 17:31:25 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	plan_checker(char *data, char *arg, t_object *plan, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		plan->origin = input_vector(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("normal", data))
		plan->normal = input_vector(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("color", data))
		plan->color = input_vector(arg, rtv->parse.nb_line);
	else
		unknown_setting("plan", rtv->parse.nb_line);
}

void	sphere_checker(char *data, char *arg, t_object *sphere, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		sphere->origin = input_vector(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("radius", data))
		sphere->radius = input_onearg(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("color", data))
		sphere->color = input_vector(arg, rtv->parse.nb_line);
	else
		unknown_setting(data, rtv->parse.nb_line);
}

void	cylinder_checker(char *data, char *arg, t_object *cylinder, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		cylinder->origin = input_vector(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("normal", data))
		cylinder->normal = input_vector(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("radius", data))
		cylinder->radius = input_onearg(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("color", data))
		cylinder->color = input_vector(arg, rtv->parse.nb_line);
	else
		unknown_setting(data, rtv->parse.nb_line);
}

void	cone_checker(char *data, char *arg, t_object *cone, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		cone->origin = input_vector(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("normal", data))
		cone->normal = input_vector(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("radius", data))
		cone->radius = input_onearg(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("color", data))
		cone->color = input_vector(arg, rtv->parse.nb_line);
	else
		unknown_setting(data, rtv->parse.nb_line);
}
