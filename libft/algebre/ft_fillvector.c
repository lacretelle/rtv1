/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillvector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:02:13 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 13:33:59 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to set all the data of a vector to specific chunck of values
**
** Attributes :
** - @vector (t_vector) : vector to modify
** - @data (double*) : chunck of data
** - @size_data (size_t) : size of the data chunck
**
** @return vector (t_vector) : vector modified
*/

t_vector	ft_fillvector(t_vector vector, double *data, size_t size_data)
{
	size_t	i;

	i = 0;
	while (i < size_data && i < vector.size)
	{
		vector.data[i] = data[i];
		i++;
	}
	return (vector);
}
