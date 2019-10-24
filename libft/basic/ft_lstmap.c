/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:22:58 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 15:01:52 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*new;
	t_list	*first;
	t_list	*prev;

	if (lst)
	{
		current = lst;
		first = f(current);
		current = current->next;
		new = first;
		while (current)
		{
			prev = new;
			if (!(new = f(current)))
				return (NULL);
			prev->next = new;
			current = current->next;
		}
		return (first);
	}
	return (NULL);
}
