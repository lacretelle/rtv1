/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:26:30 by madufour          #+#    #+#             */
/*   Updated: 2018/11/19 14:26:30 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = 0;
	if (lst && f)
	{
		if (!((new = (t_list*)malloc(sizeof(t_list)))))
			return (NULL);
		if (lst != 0)
		{
			new = f(lst);
			new->next = ft_lstmap(lst->next, f);
		}
		else
		{
			free(new);
			return (NULL);
		}
	}
	return (new);
}
