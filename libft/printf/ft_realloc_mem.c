/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:59:32 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/20 16:08:06 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_mem(char *s1, char const *s2, size_t len1, size_t len2)
{
	char	*new;
	int		i;

	i = -1;
	new = ft_strnew(len1 + len2);
	while (++i < (int)len1)
		new[i] = s1[i];
	i--;
	while (++i < (int)(len1 + len2))
		new[i] = s2[(size_t)i - len1];
	ft_strdel(&s1);
	return (new);
}
