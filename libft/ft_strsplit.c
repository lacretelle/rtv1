/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:17:55 by madufour          #+#    #+#             */
/*   Updated: 2019/02/05 18:27:56 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int word;

	word = 0;
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			word++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int *j)
{
	int i;
	int size;

	i = *j;
	size = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		size++;
	}
	*j = i;
	return (size);
}

static char	**ft_fill(char const *s, char c, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (tab[i] != 0)
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] != c)
		{
			k = 0;
			while (s[j] && s[j] != c)
			{
				tab[i][k] = s[j];
				k++;
				j++;
			}
			tab[i][k] = '\0';
		}
		i++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		word;
	int		i;
	int		j;
	int		size_word;
	char	**tab;

	if (s == 0)
		return (NULL);
	word = count_word(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	tab[word] = 0;
	i = 0;
	j = 0;
	size_word = 0;
	while (j < word)
	{
		size_word = ft_size_word(s, c, &i);
		if (!(tab[j] = (char*)malloc(sizeof(char) * (size_word + 1))))
			return (NULL);
		j++;
	}
	tab = ft_fill(s, c, tab);
	return (tab);
}
