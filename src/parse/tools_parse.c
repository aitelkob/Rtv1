/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:26:32 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/16 16:49:47 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

void            first_obj(t_rtv *rtv, t_object *obj)
{
    t_object    *tmp;

    tmp = obj;
    tmp->next = rtv->obj;
    rtv->obj = tmp;
}

/*void            first_camera(t_rtv *rtv, t_camera *camera)
{
    t_camera    *tmp;

    tmp = camera;
    tmp->next = rtv->camera;
    rtv->camera = tmp;
}*/

void            first_light(t_rtv *rtv, t_light *light)
{
    t_light    *tmp;

    tmp = light;
    tmp->next = rtv->light;
    rtv->light = tmp;
}

double          input_onearg(char *data,int nbr)
{
    char    **lines;
    double ret;

    lines = ft_strsplit(data, ' ');
     if (ft_lentab(lines) != 1)
         syntax_error(data,"bezzaf parametre",nbr);
     ret = ft_atoi(ft_strdup(lines[0]));
	 //printf("Fov= %f\n",ret);
     free_splited(lines);
     return (ret);
}

t_vector        input_vector(char *data,int nbr)
{
    char    **lines;
    t_vector vec;

    lines = ft_strsplit(data,' ');
     if (ft_lentab(lines) != 3)
        syntax_error(data,"bezzaf parametre",nbr);

    vec.x =ft_atof(lines[0]);
    vec.y =ft_atof(lines[1]);
    vec.z =ft_atof(lines[2]);
    //printf("%s line = %d->x=%0.2f,%0.2f,%.2f\n",data,nbr,vec.x,vec.y,vec.z);
    free_splited(lines);
    return (vec);
}
