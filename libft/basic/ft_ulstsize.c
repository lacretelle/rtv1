/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:15:57 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 20:19:48 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ulstsize(t_ulist *alst)
{
	size_t	size;

	size = 0;
	if (!alst)
		return (size);
	while (alst)
	{
		alst = alst->next;
		size++;
	}
	return (size);
}
