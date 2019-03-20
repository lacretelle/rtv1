/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:17:14 by madufour          #+#    #+#             */
/*   Updated: 2018/11/13 19:13:47 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] != '\0' && len > 0)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	while (len > 0)
	{
		dest[i] = '\0';
		i++;
		len--;
	}
	return (dest);
}
