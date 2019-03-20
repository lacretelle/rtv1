/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:04:03 by madufour          #+#    #+#             */
/*   Updated: 2018/11/16 12:40:06 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*str;
	unsigned char	find;

	i = 0;
	str = (unsigned char*)src;
	dest = (unsigned char*)dst;
	find = (unsigned char)c;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
		if (str[i - 1] == find)
			return (dest + i);
	}
	return (NULL);
}
