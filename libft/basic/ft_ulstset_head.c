/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstset_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:56:24 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 18:59:25 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulist	*ft_ulstset_head(t_ulist *alst)
{
	if (!alst)
		return (NULL);
	while (alst->prev)
		alst = alst->prev;
	return (alst);
}
