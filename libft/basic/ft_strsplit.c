/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:43:48 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 17:45:18 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	i;
	int		size;

	size = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	if (i == 0)
		size++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			size++;
		i++;
	}
	if (size > 0)
		return (size);
	return (0);
}

static int	set_next(char const *p, char c, int i)
{
	while (p[i] != c && p[i] != '\0')
		i++;
	while (p[i] == c && p[i] != '\0')
		i++;
	return (i);
}

static char	*add_word(char const *p, char c)
{
	size_t	i;
	char	*new;

	i = 0;
	while (p[i] != '\0' && p[i] != c)
		i++;
	new = ft_strnew(i);
	if (!new)
		return (new);
	new = ft_strncpy(new, p, i);
	return (new);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	ipos;
	size_t	size;
	int		i;

	if (!s)
		return (NULL);
	size = (size_t)count_words(s, c);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	tab[0] = 0;
	if (size == 0)
		return (tab);
	i = 0;
	if (s[i] == c)
		i = set_next(s, c, i);
	ipos = 0;
	while (s[i] != '\0')
	{
		tab[ipos] = add_word(&s[i], c);
		i = set_next(s, c, i);
		ipos++;
	}
	tab[ipos] = 0;
	return (tab);
}
