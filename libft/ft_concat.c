/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:41:11 by madufour          #+#    #+#             */
/*   Updated: 2018/11/19 15:22:04 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(char *new, char **tab, const char *glue)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j] != '\0')
			new[k++] = tab[i][j++];
		j = 0;
		while (glue[j] != '\0')
			new[k++] = glue[j++];
		i++;
	}
	new[k] = '\0';
	return (new);
}

char		*ft_concat(char **tab, const char *glue)
{
	size_t	len_glue;
	size_t	size_word;
	size_t	i;
	char	*new;

	i = 0;
	len_glue = ft_strlen(glue);
	size_word = 0;
	while (tab[i] != 0)
	{
		size_word += ft_strlen(tab[i]);
		i++;
	}
	size_word += i * len_glue;
	if (!(new = (char*)malloc(sizeof(char) * (size_word + 1))))
		return (NULL);
	new = ft_fill(new, tab, glue);
	return (new);
}
