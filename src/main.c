/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/26 11:47:55 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

int main(int ac, char **av)
{
	t_mlix mlx;
	int fd;
	int i = 0;
	if (!(fd  = open(*av, O_RDONLY)))
	{
		printf("this is fd error !");
		exit(0);
	}
	//setup(&mlx);
	char **str = NULL;

	i = get_next_line(fd ,str);
	printf("%s",str[0]);
	return (0);
}
