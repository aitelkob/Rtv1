/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/31 19:22:03 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

void            print_vect(t_vector vec,char *str)
{
	printf("%s->x=%d, %d ,%d \n",str,vec.x,vec.y,vec.z);
}

void		loop_print(t_rtv *rtv)
{
	t_object *current = rtv->obj;

	/*printf("%s\n",current->type);
	  print_vect(current->next->origin,"origin");
	  print_vect(current->next->normal,"normal");
	  print_vect(current->next->color,"color");*/
	while (current->next != NULL)
	{
		printf("%s\n",current->type);
		print_vect(current->next->next->origin,"origin");
		print_vect(current->next->next->normal,"normal");
		print_vect(current->next->next->color,"color");
		current = current->next;
	}
}

int main(int ac, char **av)
{
	t_rtv	rtv;

	parce(av[1],&rtv);
	loop_print(&rtv);
	return (0);
}
