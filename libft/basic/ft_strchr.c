/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:42:41 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/11 15:58:56 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char*)(uintptr_t)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
		if (str[i] == c && c == '\0')
			return (str + i);
	}
	return (NULL);
}
