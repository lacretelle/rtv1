/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:59:19 by madufour          #+#    #+#             */
/*   Updated: 2019/10/22 11:53:19 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/* alloue la memoire pour le tableau de tableau de rayons primaires */
static t_vec3		**rt_buildraymap()
{
	t_vec3	**tab;
	int		i;

	if (!(tab = (t_vec3**)ft_memalloc(sizeof(t_vec3*) * (SIZE_Y + 1))))
		return (NULL);
	i = -1;
	while (++i < SIZE_Y)
	{
		if (!(tab[i] = (t_vec3*)ft_memalloc(sizeof(t_vec3) * (SIZE_X + 1))))
		{
			rt_delvec3(tab);
			return (NULL);
		}
	}
	return (tab);
}

/* tableau avec vecteurs des rayons primaires*/
t_vec3		**rt_rayprim(t_vec3 p, double kw, double kh)
{
	t_vec3	**tab;
	int		i;
	int		j;
	t_vec3	tmp;

	if (!(tab = rt_buildraymap()))
		return (NULL);
	i = -1;
	while (++i < SIZE_Y)
	{
		j = -1;
		while (++j < SIZE_X)
		{
			tmp[0] = (j / kw) - p[0];
			tmp[1] = (i / kh) - p[1];
			tmp[2] = p[2];
			vec3_copy(tab[i][j], tmp);
		}
	}
	return (tab);
}
/* 
 * FOR TEST MAP VECTOR
void	printmap(t_vec3 **map)
{
	int	i;
	int	j;
	ft_printf("%.2f %.2f %.2f\t", map[0][0][0], map[0][0][1], map[0][0][2]);
	ft_printf("%.2f %.2f %.2f\t",
			map[SIZE_Y-1][SIZE_X-1][0],
			map[SIZE_Y-1][SIZE_X-1][1],
			map[SIZE_Y-1][SIZE_X-1][2]);
	
	i = -1;
	while (++i < SIZE_Y)
	{
		j = -1;
		while (++j < SIZE_X)
		{
			ft_printf("%.2f %.2f %.2f\t",
					map[i][j][0], map[i][j][1], map[i][j][2]);
		}
		ft_putendl("");
	}
}*/
