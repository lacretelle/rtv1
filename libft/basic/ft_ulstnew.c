/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:04:30 by cmaxime           #+#    #+#             */
/*   Updated: 2017/11/17 18:54:25 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ulist	*ft_ulstnew(void const *content, size_t content_size)
{
	t_ulist	*new;

	if (!(new = (t_ulist*)ft_memalloc(sizeof(t_ulist))))
		return (NULL);
	if (!content || !(new->content = (void*)ft_memalloc(content_size)))
	{
		content_size = 0;
		content = NULL;
	}
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
