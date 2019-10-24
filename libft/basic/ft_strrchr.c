/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:14:12 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/11 19:24:25 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	*str;

	str = (char*)(uintptr_t)s;
	size = ft_strlen(str);
	if (c == '\0')
		size++;
	while (size > 0)
	{
		if (str[size - 1] == c)
			return ((char*)(uintptr_t)s + size - 1);
		size--;
	}
	return (NULL);
}
