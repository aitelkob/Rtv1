/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:05:31 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/01 19:20:26 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Rtv1.h"

void            first_obj(t_rtv *rtv, t_object *obj)
{
    t_object    *tmp;

    tmp = obj;
    tmp->next = rtv->obj;
    rtv->obj = tmp;
}

void            first_light(t_rtv *rtv, t_light *light)
{
  ////////////// 5aseni ne7atha struct.h t_light
    t_light    *tmp;

    tmp = light;
    tmp->next = rtv->light;
    rtv->light = tmp;
}

t_vector        input_vector(char *data)
{
    char    **lines;
    t_vector vec;

    lines = ft_strsplit(data,' ');
    /////////////
    vec.x = ft_atoi(lines[0]);
    vec.y = ft_atoi(lines[1]);
    vec.z = ft_atoi(lines[2]);

    ////free(lines);
    return (vec);
}


void        plan_parce(t_rtv *rtv)
{
	static  t_object    *plan;
	char        *var;
	char        *data;
	char        *arg;

	if (!plan)
		if (!(plan = (t_object *)malloc(sizeof(t_object))))
			error("obj error allocat","just alloct");

	plan->type = "plane";
	rtv->parse.nb_line++;
	if (get_next_line(rtv->parse.fd, &data) == 1 && data[0] == ' ')
	{
		data = settings_cut(rtv,data,&arg);
		if (!ft_strcmp("origin",data))
			plan->origin = input_vector(arg);
		else if (!ft_strcmp("normal",data))
			plan->normal = input_vector(arg);
		else if (!ft_strcmp("color",data))
			plan->color = input_vector(arg);
		else
			unknown_setting("plan",rtv->parse.nb_line);
		free(data);
		plan_parce(rtv);
	}
	else
	{
		first_obj(rtv,plan);
		plan = NULL;
		forward(rtv,data);
	}
}

void        sphere_parce(t_rtv *rtv)
{
    static  t_object    *sphere;
    char        *var;
    char        *data;
    char        *arg;

    if (!sphere)
        if (!(sphere = (t_object *)malloc(sizeof(t_object))))
            error("obj error allocat","just alloct");

    sphere->type = "sphere";
    rtv->parse.nb_line++;
    if (get_next_line(rtv->parse.fd, &data) == 1 && data[0] == ' ')
    {
        data = settings_cut(rtv,data,&arg);
        if (!ft_strcmp("origin",data))
            sphere->origin = input_vector(arg);
        else if (!ft_strcmp("radius",data))
            sphere->radius = input_vector(arg);
        else if (!ft_strcmp("color",data))
            sphere->color = input_vector(arg);
        else
            unknown_setting(data,rtv->parse.nb_line);
        free(data);
        sphere_parce(rtv);
    }
    else
    {
        first_obj(rtv,sphere);
        sphere = NULL;
        forward(rtv,data);
    }
}

void        cylinder_parce(t_rtv *rtv)
{
    static  t_object    *cylinder;
    char        *var;
    char        *data;
    char        *arg;

    if (!cylinder)
        if (!(cylinder = (t_object *)malloc(sizeof(t_object))))
            error("obj error allocat","just alloct");

    cylinder->type = "cylinder";
    rtv->parse.nb_line++;
    if (get_next_line(rtv->parse.fd, &data) == 1 && data[0] == ' ')
    {
        data = settings_cut(rtv,data,&arg);
        if (!ft_strcmp("origin",data))
            cylinder->origin = input_vector(arg);
        else if (!ft_strcmp("normal",data))
            cylinder->normal = input_vector(arg);
        else if (!ft_strcmp("radius",data))
            cylinder->radius = input_vector(arg);
        else if (!ft_strcmp("color",data))
            cylinder->color = input_vector(arg);
        else
            unknown_setting(data,rtv->parse.nb_line);
        free(data);
        cylinder_parce(rtv);
    }
    else
    {
        first_obj(rtv,cylinder);
        cylinder = NULL;
        forward(rtv,data);
    }
}

void        cone_parce(t_rtv *rtv)
{
    static  t_object    *cone;
    char        *var;
    char        *data;
    char        *arg;

    if (!cone)
        if (!(cone = (t_object *)malloc(sizeof(t_object))))
            error("obj error allocat","just alloct");

    cone->type = "cone";
    rtv->parse.nb_line++;
    if (get_next_line(rtv->parse.fd, &data) == 1 && data[0] == ' ')
    {
        data = settings_cut(rtv,data,&arg);
        if (!ft_strcmp("origin",data))
            cone->origin = input_vector(arg);
        else if (!ft_strcmp("normal",data))
            cone->normal = input_vector(arg);
        else if (!ft_strcmp("radius",data))
            cone->radius = input_vector(arg);
        else if (!ft_strcmp("color",data))
            cone->color = input_vector(arg);
        else
            unknown_setting(data,rtv->parse.nb_line);
        free(data);
        cone_parce(rtv);
    }
    else
    {
        first_obj(rtv,cone);
        cone = NULL;
        forward(rtv,data);
    }
}

void        light_parce(t_rtv *rtv)
{
    static  t_light    *light;
    char        *var;
    char        *data;
    char        *arg;

    if (!light)
        if (!(light = (t_object *)malloc(sizeof(t_object))))
            error("obj error allocat","just alloct");

    light->type = "light";
    rtv->parse.nb_line++;
    if (get_next_line(rtv->parse.fd, &data) == 1 && data[0] == ' ')
    {
        data = settings_cut(rtv,data,&arg);
        if (!ft_strcmp("origin",data))
            light->origin = input_vector(arg);
        else if (!ft_strcmp("intensity",data))
            light->intensity = input_vector(arg);
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
