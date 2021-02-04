/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/04 18:17:34 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

/*void            print_vect(t_vector vec,char *str)
{
	printf("%s->x=%d,%d,%d\n",str,vec.x,vec.y,vec.z);
}*/

/*void		loop_print(t_rtv *rtv)
{
	t_object *current = rtv->obj;

	while (current)
	{
		if (!ft_strcmp(current->type,"plane"))
		{
			printf("%s\n",current->type);
			print_vect(current->origin,"origin");
			//print_vect(current->normal,"normal");
			print_vect(current->color,"color");
		}
		else if (!ft_strcmp(current->type,"sphere"))
		{
			printf("%s\n",current->type);
			print_vect(current->origin,"origin");
			print_vect(current->radius,"radius");
			print_vect(current->color,"color");
		}
		current = current->next;
	}
}*/

int main(int ac, char **av)
{
	t_rtv	rtv;

	//parce(av[1],&rtv);
	//loop_print(&rtv);
	setup_mlx(&rtv.mlx);
	display(&rtv.mlx);
	return (0);
}
