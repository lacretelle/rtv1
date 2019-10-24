/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setvalvector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:12:57 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 13:30:39 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to set the value of a vector at a specific index.
**
** Attributes :
** - @vector (t_vector) : vector to modify
** - @nbr (double) : value to set
** - @idx (size_t) : index of the value to set
**
** @return vector (t_vector) : vector modified
*/

t_vector	ft_setvalvector(t_vector vector, double nbr, size_t idx)
{
	if (idx < vector.size)
	{
		vector.data[idx] = nbr;
	}
	return (vector);
}
