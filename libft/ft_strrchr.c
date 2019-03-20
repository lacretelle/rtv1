/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:44:13 by madufour          #+#    #+#             */
/*   Updated: 2018/11/13 19:30:43 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	f;
	char	*tmp;

	len = 0;
	tmp = (char*)s;
	while (tmp[len] != '\0')
		len++;
	f = (char)c;
	while (tmp[len] != f && len > 0)
		len--;
	if (tmp[len] == f)
		return (tmp + len);
	return (NULL);
}
