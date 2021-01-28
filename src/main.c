/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/28 12:02:15 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

void	 ksem(char *line)
{
	char *res;
	char	**ress;
	char	**resso;

	res = ft_strtrim(line);
	free(res);
	ress = ft_strsplit(res , ':');

	printf("%s \n",ress[0]);
}

void		parce(char *av)
{
	int fd;
	char *line;

	int i = 0;
	if (!(fd  = open(av, O_RDONLY)))
	{
		printf("this is fd error !");
		exit(0);
	}

	while(get_next_line(fd ,&line))
	{
		ksem(line);
	}
	close(fd);
}

int main(int ac, char **av)
{
	parce(av[1]);
	return (0);
}
