/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:57:03 by madufour          #+#    #+#             */
/*   Updated: 2018/11/19 11:24:01 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (new)
	{
		if (*alst)
		{
			new->next = tmp;
			*alst = new;
		}
		else
			*alst = new;
	}
}
