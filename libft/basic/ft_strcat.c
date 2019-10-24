/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:38:52 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 17:23:52 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	size;
	size_t	i;
	char	*str2;

	str2 = (char*)(uintptr_t)s2;
	i = 0;
	size = ft_strlen(s1);
	while (str2[i] != '\0')
	{
		s1[size + i] = str2[i];
		i++;
	}
	s1[size + i] = '\0';
	return (s1);
}
