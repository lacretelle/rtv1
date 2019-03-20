/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:43:46 by madufour          #+#    #+#             */
/*   Updated: 2018/11/12 15:12:38 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	tmp;
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)b;
	tmp = (unsigned char)c;
	while (i < len)
	{
		str[i] = tmp;
		i++;
	}
	return (b);
}
