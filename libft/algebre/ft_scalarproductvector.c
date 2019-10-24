/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalarmultvector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:24:50 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 18:40:43 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to multiply a vector by a scalar
**
** Attributes :
** - @vector (t_vector) : vector to modify
** - @nbr (double) : scalar to multiply
**
** @return vector (t_vector) : vector multiplied by nbr
*/

t_vector	ft_scalarproductvector(t_vector vector, double nbr)
{
	size_t	i;

	i = 0;
	if (vector.size != 0)
	{
		while (i < vector.size)
		{
			vector.data[i] *= nbr;
			i++;
		}
	}
	return (vector);
}
