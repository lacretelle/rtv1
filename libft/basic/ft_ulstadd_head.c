/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:17:55 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 20:41:10 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ulstadd_head(t_ulist **alst, t_ulist *new)
{
	t_ulist	*current;

	if (alst)
	{
		current = *alst;
		while (current->prev)
			current = current->prev;
		current->prev = new;
		new->next = current;
		*alst = new;
	}
}
