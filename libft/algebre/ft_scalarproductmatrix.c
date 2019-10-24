/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalarproductmatrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:21:56 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/19 16:22:09 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to multiply a matrix to a scalar value
**
** Attributes :
** - @matrix (t_matrix) : matrix multiply
** - @nbr      (double) : double to multiply
**
** @return matrix (t_matrix) : result of the matrix multiplication
*/

t_matrix		ft_scalarproductmatrix(t_matrix matrix, double nbr)
{
    size_t  i;

    i = 0;
    while (++i <= matrix.size_n * matrix.size_m)
    {
        matrix.data[i - 1] *= nbr;
    }
    return (matrix);
}
