/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:05:50 by madufour          #+#    #+#             */
/*   Updated: 2018/11/15 15:40:17 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				i;
	int				j;
	unsigned int	l;
	char			*tmp;

	i = 0;
	tmp = (char*)haystack;
	if (needle[i] == '\0')
		return (tmp);
	while (tmp[i] != '\0' && len > 0)
	{
		j = 0;
		if (tmp[i + j] == needle[j])
		{
			l = len;
			while (tmp[i + j] == needle[j] && needle[j] != '\0' && l-- > 0)
				j++;
			if (needle[j] == '\0')
				return (tmp + i);
		}
		i++;
		len--;
	}
	return (NULL);
}
