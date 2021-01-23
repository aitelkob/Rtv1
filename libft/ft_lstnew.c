/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:33:29 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/13 20:58:55 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;

	if (!(head = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		head->content = NULL;
		head->content_size = 0;
	}
	else
	{
		if (!(head->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(head->content, (void*)content, content_size);
		head->content_size = content_size;
	}
	head->next = NULL;
	return (head);
}
