/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:31 by madufour          #+#    #+#             */
/*   Updated: 2018/11/13 19:10:36 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	find;
	unsigned char	*str;

	find = (unsigned char)c;
	str = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == find)
			return (str + i);
		i++;
	}
	return (NULL);
}
