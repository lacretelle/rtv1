/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:00:50 by madufour          #+#    #+#             */
/*   Updated: 2018/11/15 15:35:19 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int	*dst;

	if (!(dst = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	while (size--)
		dst[size] = 0;
	return ((void*)dst);
}
