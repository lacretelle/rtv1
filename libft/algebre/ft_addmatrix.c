/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:43:05 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 18:54:43 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to add a matrix to another
**
** Attributes :
** - @mat1 (t_matrix) : matrix to add
** - @mat2 (t_matrix) : matrix to add
**
** @return matrix (t_matrix) : resul tof the matrix addition
*/

t_matrix	ft_addmatrix(t_matrix mat1, t_matrix mat2)
{
	t_matrix	matrix;
	size_t		i;

	i = 0;
	if (mat1.size_m == mat2.size_m && mat1.size_n == mat2.size_n && mat1.data)
	{
		matrix = ft_matrixnew(mat1.size_m, mat2.size_n);
		while (i < matrix.size_m * matrix.size_n)
		{
			matrix.data[i] = mat1.data[i] + mat2.data[i];
			i++;
		}
	}
	else
	{
		matrix = ft_matrixnew(0, 0);
	}
	return (matrix);
}
