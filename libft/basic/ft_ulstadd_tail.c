/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:17:55 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 21:11:34 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ulstadd_tail(t_ulist **alst, t_ulist *new)
{
	t_ulist	*current;

	if (*alst)
	{
		current = *alst;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
	else
		*alst = new;
}
