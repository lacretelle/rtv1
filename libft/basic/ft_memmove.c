/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:14:56 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/11 19:23:50 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pd;
	char	*ps;

	pd = (char*)dst;
	ps = (char*)(uintptr_t)src;
	if ((pd) > (ps))
	{
		pd = pd + len;
		ps = ps + len;
		while (len--)
			*--pd = *--ps;
	}
	else
		while (len--)
			*pd++ = *ps++;
	return (dst);
}
