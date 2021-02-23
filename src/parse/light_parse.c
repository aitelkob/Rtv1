/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:22:50 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/20 17:14:42 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void						light_check(char *data, char *arg,
t_light *light, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
	{
		light->origin = input_vector(rtv, arg, rtv->parse.nb_line, data);
		free(data);
	}
	else if (!ft_strcmp("intensity", data))
	{
		light->intensity = input_onearg(rtv, arg, rtv->parse.nb_line, data);
		free(data);
	}
	else
		unknown_setting(rtv, data, rtv->parse.nb_line);
}

void					camera_check(char *data, char *arg,
t_camera *camera, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
	{
		camera->origin = input_vector(rtv, arg, rtv->parse.nb_line, data);
		free(data);
	}
	else if (!ft_strcmp("fov", data))
	{
		camera->fov = input_onearg(rtv, arg, rtv->parse.nb_line, data);
		free(data);
	}
	else if (!ft_strcmp("look_at", data))
	{
		camera->look_at = input_vector(rtv, arg, rtv->parse.nb_line, data);
		free(data);
	}
	else
		unknown_setting(rtv, data, rtv->parse.nb_line);
}

void					light_parce(t_rtv *rtv)
{
	static	t_light		*light;
	char				*data;
	char				*arg;

	if (!light)
		if (!(light = (t_light *)malloc(sizeof(t_light))))
			error("obj error allocat", "just alloct");
	rtv->parse.nb_line++;
	if (get_next_line(rtv->parse.fd, &data) == 1 && data[0] == ' ')
	{
		data = settings_cut(rtv, data, &arg);
		light_check(data, arg, light, rtv);
		light_parce(rtv);
	}
	else
	{
		first_light(rtv, light);
		light = NULL;
		forward(rtv, data);
	}
}

void					camera_parce(t_rtv *rtv)
{
	static	t_camera	*camera;
	char				*data;
	char				*arg;

	if (!camera)
		if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
			error("obj error allocat", "just alloct");
	rtv->parse.nb_line++;
	if (get_next_line(rtv->parse.fd, &data) == 1 && data[0] == ' ')
	{
		data = settings_cut(rtv, data, &arg);
		camera_check(data, arg, camera, rtv);
		camera_parce(rtv);
	}
	else
	{
		rtv->camera = camera;
		camera = NULL;
		forward(rtv, data);
	}
}
