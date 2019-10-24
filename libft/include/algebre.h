/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebre.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:44:40 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 18:55:51 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGEBRE_H
# define FT_ALGEBRE_H

# include "libft.h"

/*
** struct : vector struct to store list of double of fixed size
**
** Attributes :
** - @size (size_t) : size of data
** - @data (double*) : table of double
*/
typedef struct	s_vector
{
	size_t	size;
	double	*data;
}				t_vector;

t_vector		ft_vectornew(size_t size);
void			ft_vectordel(t_vector *vector);

t_vector		ft_setvalvector(t_vector vector, double nbr, size_t idx);
t_vector		ft_fillvector(t_vector vector, double *data, size_t size_data);

t_vector		ft_addvector(const t_vector vect1, const t_vector vect2);
t_vector		ft_multvector(t_vector vect1, t_vector vect2);
t_vector		ft_scalarproductvector(t_vector vector, double nbr);
double			ft_crossproductvector(t_vector vect1, t_vector vect2);

/*
** TODO :
** double      ft_dotproductvector(t_vector vect1, t_vector vect2);
*/

/*
** struct : matrix struct to store tab of double of fixed size
**
** Attributes :
** - @size_m (size_t) : size of data width
** - @size_n (size_t) : size of data height
** - @data (double*) : table of double
**
** example:
**  1. matrix with m = 2 and n = 3 is represented by :
** matrix =
**  [[a, b],
**   [c, d],
**   [e, f]];
** and data is [a, b, c, d, e, f]
**
**  2. matrix with m = 4 and n = 2 is represented by:
** matrix =
**  [[a, b, c, d],
**   [e, f, g, h]];
** and data is [a, b, c, d, e, f, g, h]
*/
typedef struct	s_matrix
{
	size_t	size_n;
	size_t	size_m;
	double	*data;
}				t_matrix;

t_matrix		ft_matrixnew(size_t size_m, size_t size_n);
void			ft_matrixdel(t_matrix *matrix);
t_matrix		ft_setvalmatrix(t_matrix matrix, double nbr, size_t idx_m,
		size_t idx_n);
double			ft_getvalmatrix(t_matrix matrix, size_t idx_m, size_t idx_n);

t_matrix		ft_addmatrix(t_matrix mat1, t_matrix mat2);
t_matrix		ft_scalarproductmatrix(t_matrix matrix, double nbr);
t_matrix		ft_multmatrix(t_matrix mat1, t_matrix mat2);

#endif
