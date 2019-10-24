/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:09:59 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/21 10:27:53 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ulstdelone(t_ulist **alst, void (*del)(void*, size_t))
{
	if (alst)
	{
		del((*alst)->content, sizeof(t_ulist));
		free(*alst);
		*alst = NULL;
	}
}
