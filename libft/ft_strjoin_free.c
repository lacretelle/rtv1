/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brobson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:12:05 by brobson           #+#    #+#             */
/*   Updated: 2019/01/24 15:32:27 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
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
	ft_strcpy(res, s1);
	ft_strdel(&s1);
	ft_strcat(res, s2);
	return (res);
}
