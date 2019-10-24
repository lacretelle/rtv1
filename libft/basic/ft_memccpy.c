/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:08:35 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 19:29:14 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;

	dest = (unsigned char*)dst;
	srcs = (unsigned char*)(uintptr_t)src;
	c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest[i] = srcs[i];
		if (srcs[i] == c)
			return ((void*)((uintptr_t)dst + i + 1));
		i++;
	}
	return (NULL);
}
