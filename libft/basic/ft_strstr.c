/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:17:30 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/11 16:35:40 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strcmp(haystack, needle) == 0)
		return ((char*)(uintptr_t)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char*)(uintptr_t)haystack + i);
		i++;
	}
	return (NULL);
}
