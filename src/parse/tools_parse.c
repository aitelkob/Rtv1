/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:26:32 by yait-el-          #+#    #+#             */
/*   Updated: 2021/03/08 18:02:56 by babdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				init_obj(t_object *obj)
{
	t_vector		v;

	v = (t_vector){0, 0, 0};
	obj->radius = 0;
	obj->origin = v;
	obj->translation = v;
	obj->angle = 60;
	obj->rot = v;
	obj->aim = v;
	obj->direction = v;
	obj->color = v;

}

void				first_obj(t_rtv *rtv, t_object *obj)
{
	t_object		*tmp;

	tmp = obj;
	tmp->next = rtv->obj;
	rtv->obj = tmp;
}

void				first_light(t_rtv *rtv, t_light *light)
{
	t_light			*tmp;

	tmp = light;
	tmp->next = rtv->light;
	rtv->light = tmp;
}

double				input_onearg(t_rtv *rtv, char *data, int nbr, char *head)
{
	char			**lines;
	double			ret;
	char			*tmp;

	lines = ft_strsplit(data, ' ');
	if (ft_lentab(lines) != 1)
	{
		free(data);
		free(head);
		syntax_error(rtv, data, head, nbr);
	}
	free(data);
	ret = ft_atoi(lines[0]);
	free_splited(lines);
	return (ret);
}

t_vector			input_vector(t_rtv *rtv, char *data, int nbr, char *head)
{
	char			**lines;
	t_vector		vec;

	lines = ft_strsplit(data, ' ');
	if (ft_lentab(lines) != 3)
	{
		free(data);
		free(head);
		syntax_error(rtv, "reasing", "parameters wrong in", nbr);
	}
	free(data);
	vec.x = ft_atof(lines[0]);
	vec.y = ft_atof(lines[1]);
	vec.z = ft_atof(lines[2]);
	free_splited(lines);
	return (vec);
}

t_material				input_material(t_rtv *rtv, char *data, int nbr, char *head)
{
	char			**lines;
	double			ret;
	char			*tmp;
	t_material		materiel;

	lines = ft_strsplit(data, ' ');
	if (ft_lentab(lines) != 1)
	{
		free(data);
		free(head);
		syntax_error(rtv, data, head, nbr);
	}
	free(data);
	if (ft_strequ(lines[0], "glass"))
		materiel = GLASS;
	if (ft_strequ(lines[0], "solid"))
		materiel = SOLID;
	free_splited(lines);
	return (ret);
}


