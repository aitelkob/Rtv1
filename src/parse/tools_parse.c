/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:26:32 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/20 17:05:56 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

double				input_onearg(t_rtv *rtv, char *data, int nbr,char *head)
{
	char			**lines;
	double			ret;
	char			*tmp;

	//printf("this is head (%s)\n", head);
	lines = ft_strsplit(data, ' ');
	free(data);
	if (ft_lentab(lines) != 1)
		syntax_error(rtv, data, "bezzaf parametre", nbr);
	ret = ft_atoi(lines[0]);
	free_splited(lines);
	return (ret);
}

t_vector			input_vector(t_rtv *rtv, char *data, int nbr,char *head)
{
	char			**lines;
	t_vector		vec;

	//printf("this is head (%s)\n", head);
	lines = ft_strsplit(data, ' ');
	free(data);
	if (ft_lentab(lines) != 3)
		syntax_error(rtv, data, "bezzaf parametre", nbr);
	vec.x = ft_atof(lines[0]);
	vec.y = ft_atof(lines[1]);
	vec.z = ft_atof(lines[2]);
	free_splited(lines);
	return (vec);
}
