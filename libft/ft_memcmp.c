/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:59:44 by madufour          #+#    #+#             */
/*   Updated: 2018/11/13 19:11:22 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*src;

	i = 0;
	str = (unsigned char*)s1;
	src = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && str[i] == src[i])
		i++;
	return (str[i] - src[i]);
}
