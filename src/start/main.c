/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/13 12:00:50 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

void            print_vect(t_vector vec,char *str)
{
	printf("%s->x=%0.2f,%0.2f,%0.2f\n",str,vec.x,vec.y,vec.z);
}

void		loop_print(t_rtv *rtv)
{
	t_object *current = rtv->obj;

	while (current)
	{
		if (current->type == PLANE)
		{
			printf("PLANE\n");
			print_vect(current->origin,"origin");
			print_vect(current->normal,"normal");
			print_vect(current->color,"color");
		}
		else if (current->type == SPHERE)
		{
			printf("SPHERE\n");
			print_vect(current->origin,"origin");
			printf("radius = %0.2f\n",current->radius);
			print_vect(current->color,"color");
		}
		current = current->next;
	}
}

int main(int ac, char **av)
{
	t_rtv	rtv;


	parce(av[1],&rtv);
	//loop_print(&rtv);
	setup_mlx(&rtv.mlx);
	raytracing(&rtv);
	display(&rtv.mlx);
	return (0);
}
