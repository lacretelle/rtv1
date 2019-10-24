/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:20:57 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 17:22:47 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to delete a t_matrix and free it's memory, data is set to NULL
**
** Attributes :
** - @matrix (t_matrix*) : matrix to delete
**
** @return
*/

void		ft_matrixdel(t_matrix *matrix)
{
	if (matrix->data)
	{
		free(matrix->data);
		matrix->data = NULL;
	}
}
