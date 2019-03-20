/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:12:10 by madufour          #+#    #+#             */
/*   Updated: 2018/11/20 12:04:47 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_find(t_list *begin, void *ref, int (*cmp)())
{
	t_list *list;

	list = begin;
	while (list != 0)
	{
		if ((*cmp)(list->content, ref) == 0)
			return (list);
		list = list->next;
	}
	return (0);
}
