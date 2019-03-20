/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:37:06 by madufour          #+#    #+#             */
/*   Updated: 2018/11/13 19:09:58 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*dest;
	char			*str;

	dest = (char*)dst;
	str = (char*)src;
	i = 0;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		len--;
		while ((len + 1) != 0)
		{
			dest[len] = str[len];
			len--;
		}
	}
	else
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	return (dest);
}
