/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:10:05 by madufour          #+#    #+#             */
/*   Updated: 2018/11/20 12:04:24 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_rev(t_list *list)
{
	t_list *begin;
	t_list *temp;

	if (list->next)
	{
		begin = list->next;
		temp = ft_rev(list->next);
		begin->next = list;
	}
	else
		return (list);
	return (temp);
}

void			ft_lst_reverse(t_list **begin)
{
	t_list	*list;

	if (begin != 0)
	{
		if (*begin != 0)
		{
			list = *begin;
			*begin = ft_rev(*begin);
			list->next = 0;
		}
	}
}
