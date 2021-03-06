/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/03/06 10:11:58 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int ac, char **av)
{
	t_rtv	rtv;

	if (ac == 2 && (access(av[1], F_OK)) == 0)
	{
		parce(av[1], &rtv);
		if (rtv.camera->check != 1)
			syntax_error(&rtv, av[1], "camera parce plz  ", rtv.parse.nb_line);
		setup_mlx(&rtv.mlx);
		raytracing(&rtv);
		display(&rtv, &rtv.mlx);
	}
	else
		syntax_error(&rtv, av[1], "please parse file next time ", 0);
	return (0);
}
