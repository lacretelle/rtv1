/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:29:36 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 16:58:00 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_trimsize(char *s)
{
	int		size;
	int		i;

	size = (int)ft_strlen(s) - 1;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[size] == ' ' || s[size] == '\n' || s[size] == '\t') && size >= 0)
		size--;
	size = size - i + 1;
	if (size > 0)
		return ((size_t)size);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = get_trimsize((char*)(uintptr_t)s);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	new = ft_strsub(s, (unsigned int)i, size);
	return (new);
}
