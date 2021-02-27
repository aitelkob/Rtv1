/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:07:15 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/26 17:20:56 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	plan_checker(char *data, char *arg, t_object *plan, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		plan->origin = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("normal", data))
		plan->normal = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("color", data))
		plan->color = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("rot", data))
		plan->rot = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else
	{
		free(data);
		unknown_setting(rtv, "plan", rtv->parse.nb_line);
	}
	free(data);
}

void	sphere_checker(char *data, char *arg, t_object *sphere, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		sphere->origin = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("radius", data))
		sphere->radius = input_onearg(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("color", data))
		sphere->color = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else
	{
		free(data);
		unknown_setting(rtv, "sphere", rtv->parse.nb_line);
	}
	free(data);
}

void	cylinder_checker(char *data, char *arg, t_object *cylinder, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		cylinder->origin = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("normal", data))
		cylinder->normal = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("radius", data))
		cylinder->radius = input_onearg(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("rot", data))
		cylinder->rot = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("color", data))
		cylinder->color = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else
	{
		free(data);
		unknown_setting(rtv, "cylinder", rtv->parse.nb_line);
	}
	free(data);
}

void	cone_checker(char *data, char *arg, t_object *cone, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		cone->origin = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("normal", data))
		cone->normal = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("radius", data))
		cone->radius = input_onearg(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("rot", data))
		cone->rot = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else if (!ft_strcmp("color", data))
		cone->color = input_vector(rtv, arg, rtv->parse.nb_line, data);
	else
	{
		free(data);
		unknown_setting(rtv, "cone", rtv->parse.nb_line);
	}
	free(data);
}
