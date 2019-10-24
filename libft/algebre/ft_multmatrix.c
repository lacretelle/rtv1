/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multmatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:28:47 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/19 16:28:48 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to multiply two matrix
**
** Attributes :
** - @mat1 (t_matrix) : matrix to multiply
** - @mat2 (t_matrix) : matrix to multiply
**
** @return matrix (t_matrix) : result of the matrix multiplication
*/

static double   get_cell_val(t_matrix mat1, t_matrix mat2, size_t m, size_t n)
{
    size_t  i;
    double  value;

    i = 0;
    value = 0.0;
    while (++i <= mat1.size_m)
    {
        value += ft_getvalmatrix(mat1, m, i - 1)
                * ft_getvalmatrix(mat2, i - 1, n);
    }
    return (value);
}

t_matrix		ft_multmatrix(t_matrix mat1, t_matrix mat2)
{
    t_matrix    matrix;
    size_t      i;
    size_t      j;
    double      value;

    if (mat1.size_m == mat2.size_n)
    {
        matrix = ft_matrixnew(mat2.size_m, mat1.size_n);
        i = 0;
        while (++i <= matrix.size_m)
        {
            j = 0;
            while (++j <= matrix.size_n)
            {
                value = get_cell_val(mat1, mat2, i - 1, j - 1);
                matrix = ft_setvalmatrix(matrix, value, i - 1, j - 1);
            }
        }
    }
    else
        matrix = ft_matrixnew(0, 0);
    return (matrix);
}
