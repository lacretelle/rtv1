/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:23:31 by madufour          #+#    #+#             */
/*   Updated: 2018/11/20 12:05:30 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushback(t_list **begin, t_list *new)
{
	t_list	*list;

	if (new)
	{
		if (*begin)
		{
			list = *begin;
			while (list->next != 0)
				list = list->next;
			list->next = new;
			new->next = NULL;
		}
		else
			*begin = new;
	}
	return (*begin);
}
