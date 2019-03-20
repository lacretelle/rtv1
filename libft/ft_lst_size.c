/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:03:03 by madufour          #+#    #+#             */
/*   Updated: 2018/11/20 12:01:30 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size(t_list *begin)
{
	int		count;
	t_list	*temp;

	if (begin == 0)
		return (0);
	temp = begin;
	count = 0;
	while (temp->next != 0)
	{
		temp = temp->next;
		count++;
	}
	if (temp->next == 0)
		count++;
	return (count);
}
