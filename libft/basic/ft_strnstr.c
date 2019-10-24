/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:15:11 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 16:59:01 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		size;

	i = 0;
	size = (int)(len - ft_strlen(needle));
	if (ft_strcmp(haystack, needle) == 0 && ft_strlen(haystack) >= len)
		return ((char*)(uintptr_t)haystack);
	while (haystack[i] != '\0' && (int)i <= size)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] != '\0'
				&& haystack[i + j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char*)(uintptr_t)haystack + i);
		i++;
	}
	return (NULL);
}
