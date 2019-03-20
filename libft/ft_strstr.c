/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:56:24 by madufour          #+#    #+#             */
/*   Updated: 2018/11/13 19:26:34 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = (char*)haystack;
	if (needle[i] == '\0')
		return (res);
	while (res[i] != '\0')
	{
		j = 0;
		if (res[i + j] == needle[j])
		{
			while (res[i + j] == needle[j] && needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
				return (res + i);
		}
		i++;
	}
	return (NULL);
}
