/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addvector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:04:31 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 13:36:30 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algebre.h>

/*
** Function to add to vectors
** Exception : if vect1 and vect2 are not the same size, return an empty vector
**
** Attributes :
** - @vect1 (const t_vector) : vector to add
** - @vect2 (const t_vector) : other vector to add
**
** @return vector (t_vector) : result of the addition
*/

t_vector	ft_addvector(const t_vector vect1, const t_vector vect2)
{
	t_vector	vector;
	double		nbr;
	size_t		i;

	i = 0;
	if (vect1.size == vect2.size && vect1.size != 0)
	{
		vector = ft_vectornew(vect2.size);
		while (i < vect2.size)
		{
			nbr = vect1.data[i] + vect2.data[i];
			vector = ft_setvalvector(vector, nbr, i);
			i++;
		}
	}
	else
	{
		return (ft_vectornew(0));
	}
	return (vector);
}
