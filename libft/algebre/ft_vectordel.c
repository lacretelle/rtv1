/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectordel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:37:45 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 17:23:06 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to delete a vector and free it's memory, data is set to NULL
**
** Attributes :
** - @vector (t_vector*) : vector to delete
**
** @return
*/

void	ft_vectordel(t_vector *vector)
{
	if (vector->data)
	{
		free(vector->data);
		vector->data = NULL;
		vector->size = 0;
	}
}
