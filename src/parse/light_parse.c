/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:22:50 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/03 17:10:53 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

void        light_parce(t_rtv *rtv)
{
    static  t_light    *light;
    char        *var;
    char        *data;
    char        *arg;

    if (!light)
        if (!(light = (t_light *)malloc(sizeof(t_light))))
            error("obj error allocat","just alloct");

    rtv->parse.nb_line++;
    if (get_next_line(rtv->parse.fd, &data) == 1 && data[0] == ' ')
    {
        data = settings_cut(rtv,data,&arg);
        if (!ft_strcmp("origin",data))
            light->origin = input_vector(arg,rtv->parse.nb_line);
        else if (!ft_strcmp("intensity",data))
            light->intensity = atoi(arg);
        else
            unknown_setting(data,rtv->parse.nb_line);
        free(data);
        light_parce(rtv);
    }
    else
    {
      //// to do
        first_light(rtv,light);
        light = NULL;
        forward(rtv,data);
    }
}
