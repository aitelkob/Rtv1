/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:39:37 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/20 15:50:09 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void free_objects(t_rtv  *rt)
{
    t_obj   *next;

    while (rt && rt->objects)
    {
        next = rt->objects->next;
        free(rt->objects);
        rt->objects = next;
    }
}

static void free_lights(t_rtv *rt)
{
    t_light *next;

    while (rt && rt->lights)
    {
        next = rt->lights->next;
        free(rt->lights);
        rt->lights = next;
    }
}

void		exiting_program(t_rtv *rtv)
{
	free(rtv->camera);
	free_lights(rtv);
	free_objects(rtv);

}
