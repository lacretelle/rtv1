/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstset_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:59:40 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 19:01:04 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulist	*ft_ulstset_tail(t_ulist *alst)
{
	if (!alst)
		return (NULL);
	while (alst->next)
		alst = alst->next;
	return (alst);
}
