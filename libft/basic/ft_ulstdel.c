/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:13:49 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 19:21:04 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ulstdel(t_ulist **alst, void (*del)(void*, size_t))
{
	t_ulist	*next;
	t_ulist	*current;

	if (alst)
	{
		current = *alst;
		while (current->prev)
			current = current->prev;
		while (current)
		{
			next = current->next;
			ft_ulstdelone(&current, del);
			current = next;
		}
		*alst = NULL;
	}
}
