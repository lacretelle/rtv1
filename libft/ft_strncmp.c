/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:32:35 by madufour          #+#    #+#             */
/*   Updated: 2018/11/14 14:51:23 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*str;

	if (n == 0)
		return (0);
	src = (unsigned char*)s1;
	str = (unsigned char*)s2;
	while (*src == *str && n > 1 && *src != '\0')
	{
		src++;
		str++;
		n--;
	}
	return (*src - *str);
}
