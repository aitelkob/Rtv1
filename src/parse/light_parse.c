/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:22:50 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/13 10:46:54 by yait-el-         ###   ########.fr       */
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

/*void        camera_parce(t_rtv *rtv)
{
    static  t_camera    *camera;
    char        *data;
    char        *arg;

    if (!camera)
        if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
            error("obj error allocat","just alloct");

    rtv->parse.nb_line++;
    if (get_next_line(rtv->parse.fd, &data) == 1 && data[0] ==' ')
    {
        data = settings_cut(rtv,data,&arg);
        if (!ft_strcmp("origin",data))
            camera->origin = input_vector(arg,rtv->parse.nb_line);
        else if (!ft_strcmp("fov",data))
            camera->fov = input_onearg(arg,rtv->parse.nb_line);
        else if (!ft_strcmp("look_at",data))
            camera->look_at = input_vector(arg,rtv->parse.nb_line);
        else
            unknown_setting(data,rtv->parse.nb_line);
        free(data);
        camera_parce(rtv);
    }
    else
    {
        first_camera(rtv,camera);
        camera = NULL;
        forward(rtv,data);
    }
}*/
