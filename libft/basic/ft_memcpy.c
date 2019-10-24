/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:55:13 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 18:15:41 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;

	srcs = (unsigned char*)(uintptr_t)src;
	dest = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (dst);
}
