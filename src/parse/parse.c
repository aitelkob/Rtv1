/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:21:21 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/31 17:43:28 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"
#include "fuction.c"



void            first_obj(t_rtv *rtv, t_object *obj)
{
	t_object    *tmp;

	tmp = obj;
	tmp->next = rtv->obj;
	rtv->obj = tmp;
}

t_vector		input_vector(char *data)
{
	char	**lines;
	t_vector vec;

	lines = ft_strsplit(data,' ');
	/////////////
	vec.x = ft_atoi(lines[0]);
	vec.y = ft_atoi(lines[1]);
	vec.z = ft_atoi(lines[2]);

	////free(lines);
	return (vec);
}

void			print_vect(t_vector vec,char *str)
{
	printf("%s->x=%d\n",str,vec.x);
	printf("%s->y=%d\n",str,vec.y);
	printf("%s->z=%d\n",str,vec.z);
}

void	error(char *str,char *where)
{
	printf("%s in ===(%s)\n",str,where);
	exit(0);
}
char    *ksem(char *line,char **arg);
void        forward(t_rtv *rtv);


char	*ksem(char *line,char **arg)
{
	char *res;
	char	**lines;
	char	*resso;

	lines = ft_strsplit(line,':');
	res = ft_strtrim(lines[0]);
	*arg = ft_strdup(lines[1]);
	printf("%s\n",*arg);
	return (res);
}

char		*parse_cut(t_rtv *rtv)
{
	char    *setting;
	char    *strtrim;

	setting = rtv->parse.line;
	if (!setting || setting[0] == '\0')
	{
		printf("de5ale");
		return ("\0");
	}
	strtrim = ft_strtrim(setting);
	if (strtrim[0] == '#')
		return (strtrim);
	if (strtrim[ft_strlen(strtrim) - 1] != ':' &&
			strtrim[ft_strlen(strtrim) - 1] != '1' &&
			strtrim[ft_strlen(strtrim) - 1] != '0')
		error("parse cut",setting);
	strtrim[ft_strlen(strtrim) - 1] = '\0';
	return (strtrim);
}

void		forward(t_rtv *rtv)
{
	char	*head;
	char	**ll;

	head = parse_cut(rtv);
	printf("head found == %s in line %d \n",head, rtv->parse.nb_line);
	if (!ft_strcmp(head,"plane"))
	{
		plan_parce(rtv);
	}
	/*else if (!ft_strcmp(head,"sphere"))
		printf("line == %s\n",head);
	else if (!ft_strcmp(head,"cone"))
		printf("line == %s\n",head);*/
	else if (!head || head[0] == '\0' || head[0] == ' ')
	{
		printf("de5ale ou nn \n");
		return;
	}
	else
		error("header parse error\n",head);
	free(head);
}

void		parce(char *av,t_rtv *rtv)
{
	char *test;
	if (!(rtv->parse.fd  = open(av, O_RDONLY)))
		error("this is fd error !","fd ");
	rtv->parse.nb_line = 0;
	while(get_next_line(rtv->parse.fd ,&rtv->parse.line))
	{
		forward(rtv);
		free(rtv->parse.line);
	}
	if (rtv->parse.fd == -1)
		error("fd matsedche \n","fd matsedch");
}
