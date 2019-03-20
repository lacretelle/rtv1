/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:40:03 by madufour          #+#    #+#             */
/*   Updated: 2018/11/19 14:03:29 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	size_dest;
	unsigned int	size_src;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size <= size_dest)
		return (size_src + size);
	ft_strncat(dest, src, (size - size_dest - 1));
	return (size_dest + size_src);
}
