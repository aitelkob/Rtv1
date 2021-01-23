/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:28:18 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/14 23:53:21 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*head;
	t_list	*tmp;

	head = *alst;
	while (head)
	{
		tmp = head->next;
		del(head->content, head->content_size);
		free(head);
		head = tmp;
	}
	*alst = NULL;
}
