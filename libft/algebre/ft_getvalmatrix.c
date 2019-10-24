/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setvalmatrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:26:00 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 18:54:58 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to get the value at a specific index in a matrix
**
** Attributes :
** - @matrix (t_matrix) : matrix to modify
** - @idx_m    (size_t) : index of width
** - @idx_n    (size_t) : index of height
**
** @return result (double) : value at the specified index
*/

double	ft_getvalmatrix(t_matrix matrix, size_t idx_m, size_t idx_n)
{
	double	result;

	result = 0;
	if (idx_n < matrix.size_n && idx_m < matrix.size_m)
	{
		result = matrix.data[idx_m + idx_n * matrix.size_m];
	}
	return (result);
}
