/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:27 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/17 18:47:49 by yait-el-         ###   ########.fr       */
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
	t_camera *curr = rtv->camera;
	t_light *tmp = rtv->light;

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
	while (tmp)
	{
		print_vect(tmp->origin,"light");
		printf(" intensiti %f \n",tmp->intensity);
		tmp = tmp->next;
	}

	if (rtv->camera)
	{	
				printf("camera\n");
				print_vect(rtv->camera->origin,"origin");
				printf("fov = %0.2f\n",rtv->camera->fov);
				print_vect(rtv->camera->look_at,"look_at");
	}
}

int main(int ac, char **av)
{
	t_rtv	rtv;

	(void)ac;
	parce(av[1],&rtv);
	//loop_print(&rtv);
	setup_mlx(&rtv.mlx);
	raytracing(&rtv);
	display(&rtv.mlx);
	return (0);
}
