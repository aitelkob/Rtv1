/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:05:31 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/31 19:14:54 by yait-el-         ###   ########.fr       */
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
			error("plane error",data);
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

