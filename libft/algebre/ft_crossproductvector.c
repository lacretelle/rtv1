/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crossproductvector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:50:39 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 14:34:54 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to calculate the cross product of two vectors
**
** Attributes :
** - @vect1 (t_vector) : first vector
** - @vect2 (t_vector) : second vector
**
** @return result (double) : scalar result
*/

double	ft_crossproductvector(t_vector vect1, t_vector vect2)
{
	double	result;
	size_t	i;

	i = 0;
	result = 0;
	if (vect1.size == vect2.size && vect1.size != 0)
	{
		while (i < vect1.size)
		{
			result += vect1.data[i] * vect2.data[i];
			i++;
		}
	}
	return (result);
}
