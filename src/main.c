/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/28 19:30:08 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

void	error(char *str)
{
	printf("%s\n",str);
	exit(0);
}

/*void	if_head_obj(char *str)
{
	if (ft_strcmp(str,"plan") || ft_strcmp(str,"sphere") || ft_strcmp(str,"cylider") || ft_strcmp(str,"cone"))
		return (1);
	return (0);
}

char	*ksem_arg(char *line)
{

}*/

char	*ksem(char *line)
{
	char *res;
	char	**ress;
	char	*resso;

	res = ft_strtrim(line);
	free(res);
	ress = ft_strsplit(res , ':');
	resso = ft_strtrim(ress[0]);

	return (resso);
}

char *parse_cut(t_rtv *rtv)
{
    char    *cmp;

    cmp = ft_strtrim(rtv->parse.line);
	if (cmp[0] == '#')
		return (cmp);
	if ((cmp[ft_strlen(cmp) - 1] != ':') &&
			(cmp[ft_strlen(cmp) - 1] != '1') && 
			(cmp[ft_strlen(cmp) - 1] != '0'))
		error("missing :");
	cmp[ft_strlen(cmp) - 1] = '\0';
	return (cmp);
}

void		parce(char *av,t_rtv *rtv)
{
	char *test;

	if (!(rtv->parse.fd  = open(av, O_RDONLY)))
		error("this is fd error !");

	while(get_next_line(rtv->parse.fd ,&rtv->parse.line))
	{
		test = parse_cut(rtv);
		if (!ft_strcmp(test,"plane"))
			printf("line == %s\n",test);
		else if (!ft_strcmp(test,"sphere"))
			printf("line == %s\n",test);
		else if (!ft_strcmp(test,"cone"))
			printf("line == %s\n",test);
		//printf("%s\n",test);
		free(rtv->parse.line);
	}
	if (rtv->parse.fd == -1)
		error("fd matsedche \n");
}

int main(int ac, char **av)
{
	t_rtv	rtv;

	parce(av[1],&rtv);
	return (0);
}
