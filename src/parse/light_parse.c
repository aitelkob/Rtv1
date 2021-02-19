/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:22:50 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/19 17:49:17 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					light_check(char *data, char *arg,
t_light *light, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		light->origin = input_vector(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("intensity", data))
		light->intensity = atoi(arg);
	else
		unknown_setting(data, rtv->parse.nb_line);
}

void					camera_check(char *data, char *arg,
t_camera *camera, t_rtv *rtv)
{
	if (!ft_strcmp("origin", data))
		camera->origin = input_vector(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("fov", data))
		camera->fov = input_onearg(arg, rtv->parse.nb_line);
	else if (!ft_strcmp("look_at", data))
		camera->look_at = input_vector(arg, rtv->parse.nb_line);
	else
		unknown_setting(data, rtv->parse.nb_line);
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
		free(data);
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
		free(data);
		camera_parce(rtv);
	}
	else
	{
		rtv->camera = camera;
		forward(rtv, data);
	}
}
