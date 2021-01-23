/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:36:05 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/04/19 16:00:26 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	head = f(lst);
	tmp = head;
	lst = lst->next;
	while (lst)
	{
		head->next = f(lst);
		head = head->next;
		lst = lst->next;
	}
	return (tmp);
}
