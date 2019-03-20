/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:47:51 by madufour          #+#    #+#             */
/*   Updated: 2018/11/15 14:25:10 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (s == 0)
		return (NULL);
	while (s[size] != '\0')
		size++;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
