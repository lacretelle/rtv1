/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:11:06 by madufour          #+#    #+#             */
/*   Updated: 2018/11/19 15:34:01 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	size_t	len;
	void	*new;
	char	*tmp;

	if (ptr == 0)
		return (malloc(size));
	len = ft_strlen((const char*)ptr);
	if (size <= len)
		return (ptr);
	if (!(tmp = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	new = (void*)tmp;
	new = ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}
