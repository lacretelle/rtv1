/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:04:16 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 18:37:11 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size <= size_dst)
		return (size + size_src);
	dst = ft_strncat(dst, src, size - size_dst - 1);
	return (size_dst + size_src);
}
