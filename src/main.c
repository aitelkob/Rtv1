/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/26 17:13:40 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"


int main(int ac, char **av)
{
	t_mlix mlx;
	int fd;
	char *line;

	int i = 0;
	if (!(fd  = open(*av, O_RDONLY)))
	{
		printf("this is fd error !");
		exit(0);
	}
	//setup(&mlx);
	char **str = NULL;

	if (get_next_line(fd ,&line))
		printf("%s",line);

	return (0);
}
