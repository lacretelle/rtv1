/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:37:21 by cmaxime           #+#    #+#             */
/*   Updated: 2019/01/23 12:16:12 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_pushback(t_list **front, t_list *new)
{
	t_list	*list;

	if (*front == NULL)
	{
		*front = new;
	}
	else
	{
		list = *front;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
