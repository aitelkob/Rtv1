/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:39:37 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/23 08:59:46 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	void			free_objects(t_rtv *rtv)
{
	t_object			*next;

	while (rtv && rtv->obj)
	{
		next = rtv->obj->next;
		free(rtv->obj);
		rtv->obj = next;
	}
}

static	void			free_lights(t_rtv *rtv)
{
	t_light				*next;

	while (rtv && rtv->light)
	{
		next = rtv->light->next;
		free(rtv->light);
		rtv->light = next;
	}
}

void					exiting_program(t_rtv *rtv)
{
	ft_destroy(&rtv->mlx);
	if (rtv->camera)
		free(rtv->camera);
	if (rtv->light)
		free_lights(rtv);
	if (rtv->obj)
		free_objects(rtv);
	exit(0);
}
