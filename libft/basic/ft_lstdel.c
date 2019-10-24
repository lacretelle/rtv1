/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:13:49 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 16:55:55 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;
	t_list	*current;

	if (alst)
	{
		current = *alst;
		while (current)
		{
			next = current->next;
			ft_lstdelone(&current, del);
			current = next;
		}
		*alst = NULL;
	}
}
