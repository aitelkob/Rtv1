/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:39:37 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/20 17:45:02 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void free_objects(t_rtv  *rt)
{
    t_object   *next;

    while (rt && rt->obj)
    {
        next = rt->obj->next;
        free(rt->obj);
        rt->obj = next;
    }
}

static void free_lights(t_rtv *rt)
{
    t_light *next;

    while (rt && rt->light)
    {
        next = rt->light->next;
        free(rt->light);
        rt->light = next;
    }
}

void		exiting_program(t_rtv *rtv)
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
