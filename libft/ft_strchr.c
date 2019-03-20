/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:33:41 by madufour          #+#    #+#             */
/*   Updated: 2018/11/13 19:25:09 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	f;
	char	*res;

	i = 0;
	f = (char)c;
	res = (char*)s;
	while (res[i] != f && res[i] != '\0')
		i++;
	if (res[i] == f)
		return (res + i);
	return (NULL);
}
