/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectornew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:09:38 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 17:15:57 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to create a new t_vector struct, data fields are initialized to 0
** Exception: if size = 0, data is set to NULL
**
** @param1 size (size_t) : size of vector
**
** @return vector (t_vector) : vector created
*/

t_vector	ft_vectornew(size_t size)
{
	t_vector	vector;
	size_t		i;

	i = 0;
	if (size == 0)
	{
		vector.size = 0;
		vector.data = NULL;
	}
	else
	{
		vector.size = size;
		if (!(vector.data = (double*)ft_memalloc(size * sizeof(double))))
		{
			vector.size = 0;
		}
	}
	return (vector);
}
