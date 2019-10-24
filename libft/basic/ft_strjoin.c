/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:21:58 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/14 17:20:21 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!new)
		return (new);
	new = ft_strcpy(new, s1);
	new = ft_strcat(new, s2);
	return (new);
}
