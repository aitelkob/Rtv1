/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/27 17:54:04 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

void	 ksem(char *line)
{
	char *res;

	res = ft_strtrim(line);

	printf("%s \n",res);
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
}

int main(int ac, char **av)
{
	parce(av[1]);
	return (0);
}
