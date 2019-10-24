/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:10:38 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 18:54:07 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to create a new t_matrix struct, data fields are initialized to 0
** Exception: if size_m or size_n = 0, data is set to NULL
**
** Attributes :
** - @size_m (size_t) : width of the matrix
** - @size_n (size_t) : height of the matrix
**
** @return vector (t_matrix) : matrix created
*/

t_matrix	ft_matrixnew(size_t size_m, size_t size_n)
{
	t_matrix	matrix;

	if (size_m && size_n)
	{
		matrix.size_m = 0;
		matrix.size_n = 0;
		if (!(matrix.data = (double*)ft_memalloc(size_m * size_n
						* sizeof(double))))
		{
			matrix.size_m = 0;
			matrix.size_n = 0;
		}
	}
	else
	{
		matrix.size_m = 0;
		matrix.size_n = 0;
		matrix.data = NULL;
	}
	return (matrix);
}
