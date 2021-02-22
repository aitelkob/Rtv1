/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:43:51 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/20 17:27:39 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			error(char *str, char *where)
{
	printf("%s in ===(%s)\n", str, where);
	exit(0);
}

char			*settings_cut(t_rtv *rtv, char *variable, char **data)
{
	char		**line;
	char		*option;

	line = ft_strsplit(variable, ':');
	if (ft_lentab(line) != 2)
	{
		free(variable);
		free(*data);
		syntax_error(rtv, "variable", "somthing wrong with  file",
		rtv->parse.nb_line);
	}
	free(variable);
	option = ft_strtrim(line[0]);
	*data = ft_strdup(line[1]);
	free_splited(line);
	return (option);
}

char			*name_cut(t_rtv *rtv, char *line)
{
	char		*strtrim;

	if (!line || line[0] == '\0')
		return ("\0");
	strtrim = ft_strtrim(line);
	if (strtrim[ft_strlen(strtrim) - 1] != ':' &&
			strtrim[ft_strlen(strtrim) - 1] != '1' &&
			strtrim[ft_strlen(strtrim) - 1] != '0')
		syntax_error(rtv, line, "somthing wrong with file ",
		rtv->parse.nb_line);
	strtrim[ft_strlen(strtrim) - 1] = '\0';
	free(line);
	return (strtrim);
}

void			forward(t_rtv *rtv, char *line)
{
	char		*obj_name;

	obj_name = name_cut(rtv, line);
	if (!ft_strcmp(obj_name, "camera"))
		camera_parce(rtv);
	else if (!ft_strcmp(obj_name, "light"))
		light_parce(rtv);
	else if (!ft_strcmp(obj_name, "plane"))
		plan_parce(rtv);
	else if (!ft_strcmp(obj_name, "sphere"))
		sphere_parce(rtv);
	else if (!ft_strcmp(obj_name, "cylinder"))
		cylinder_parce(rtv);
	else if (!ft_strcmp(obj_name, "cone"))
		cone_parce(rtv);
	else if (!obj_name || obj_name[0] == '\0' || obj_name[0] == '\n')
	{
		free(line);
		return ;
	}
	else
	{
		free(obj_name);
		free(line);
		syntax_error(rtv, "name of obj", "note good", rtv->parse.nb_line);
	}
	free(obj_name);
}

void			parce(char *av, t_rtv *rtv)
{
	if (!(rtv->parse.fd = open(av, O_RDONLY)))
		error("this is fd error !", "fd ");
	rtv->parse.nb_line = 0;
	rtv->obj = NULL;
	rtv->light = NULL;
	if (get_next_line(rtv->parse.fd, &rtv->parse.line))
	{
		rtv->parse.nb_line++;
		forward(rtv, rtv->parse.line);
	}
	if (rtv->parse.fd == -1)
		error("fd matsedche \n", "fd matsedch");
}
