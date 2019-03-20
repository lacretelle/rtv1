/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:07:04 by madufour          #+#    #+#             */
/*   Updated: 2018/11/20 12:05:09 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *begin, size_t nbr)
{
	t_list	*temp;
	size_t	i;

	if (begin == 0)
		return (NULL);
	temp = begin;
	i = 0;
	while (temp != 0 && i < nbr)
	{
		temp = temp->next;
		i++;
	}
	return (i == nbr ? temp : NULL);
}
