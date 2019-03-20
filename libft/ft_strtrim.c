/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:48:28 by madufour          #+#    #+#             */
/*   Updated: 2019/03/02 17:05:54 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(char const *s)
{
	int tmp;

	tmp = 0;
	while ((*s == ' ' || *s == ',' || *s == '\n' || *s == '\t') && *s != '\0')
	{
		s++;
		tmp++;
	}
	return (tmp);
}

static int	ft_size_tot(char const *s, int size)
{
	int j;

	j = 0;
	while ((s[size] == ' ' || s[size] == ',' || s[size] == '\n'
				|| s[size] == '\t') && size >= 0)
	{
		j++;
		size--;
	}
	return (j);
}

static char	*ft_fill_trim(char const *s, char *res, int size, int bf)
{
	int i;

	i = 0;
	while (i < size)
	{
		res[i] = s[bf];
		i++;
		bf++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s)
{
	int		bf;
	int		af;
	int		size;
	char	*res;

	if (s == 0)
		return (NULL);
	size = ft_strlen(s);
	bf = ft_size(s);
	af = ft_size_tot(s, size - 1);
	if (bf == size)
		size = 0;
	else
		size = size - af - bf;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res = ft_fill_trim(s, res, size, bf);
	return (res);
}
