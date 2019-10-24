/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setvalmatrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:26:00 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 18:16:19 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to set the value at a specific index in a matrix
**
** Attributes :
** - @matrix (t_matrix) : matrix to modify
** - @nbr      (double) : nbr to set in the matrix
** - @idx_m    (size_t) : index of width
** - @idx_n    (size_t) : index of height
**
** @return matrix (t_matrix) : matrix modified
*/

t_matrix	ft_setvalmatrix(t_matrix matrix, double nbr, size_t idx_m,
				size_t idx_n)
{
	if (idx_n < matrix.size_n && idx_m < matrix.size_m)
	{
		matrix.data[idx_m + idx_n * matrix.size_m] = nbr;
	}
	return (matrix);
}
