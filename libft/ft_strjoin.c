/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:47:42 by madufour          #+#    #+#             */
/*   Updated: 2018/11/16 10:46:05 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*res;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (!(res = (char*)malloc(sizeof(char) * (size_s1 + size_s2 + 1))))
		return (NULL);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	return (res);
}
