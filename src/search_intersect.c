/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:50:55 by madufour          #+#    #+#             */
/*   Updated: 2019/10/25 11:46:04 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double dot_product(t_vec3 v, t_vec3 u)
{
	return v[0] * u[0] + v[1] * u[1] + v[2] * u[2];
}

size_t	rt_solvequadratic(double a, double b, double c)
{
	double	delta;
	//int		*t;
	//double	q;

	delta = b * b - 4 * a * c;
	//q = 0;
	//t = 0;
	if (delta < 0)
		return 0;
	else
		return 1;
	/*else if (delta == 0)
	{
		t[0] = 1;
		t[1] = - 0.5 * b / a;
	}
	else
	{
		q = (b > 0) ? -0.5 * (b + sqr(delta)) : -0.5 * (b - sqr(delta));
		t[0] = q / a;
		t[1] = c / q;
	}*/
}
size_t	rt_intersect(t_vec3 v1, t_vec3 v2, double r)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = dot_product(v2, v2);
	b = 2 * dot_product(v1, v2);
	c = dot_product(v1, v1) - (r * r);
	delta = b * b - 4.0 * a * c;
	if (delta < 0.0)
		return 0;
	else 
		return 1;
}
//malloc int**
int	**rt_init_tab(void)
{
	int	**tab;
	int i;

	if (!(tab = (int**)malloc(sizeof(int*) * (SIZE_Y + 1))))
		return NULL;
	 i = -1;
	while (++i < SIZE_Y)
	{
		if (!(tab[i] = (int*)malloc(sizeof(int) * (SIZE_X + 1))))
		{
			//clear tab int
			return NULL;
		}
	}
	return tab;
}

/*
 * Function for calculate if ray intersect an object => instead shpere
 * @return int** contains if ray intersect 1 or not 0
 */
int	**search_intersect(t_scene s, t_vec3 **map)
{
	int		**tab;
	size_t	i;
	size_t	j;
	size_t	o;

	//calcul pour chaque pixel if intersect or not
	// CH^2 = OC^2 - OH^2
	i = -1;
	o = s.sphere.rayon;
	if (!(tab = rt_init_tab()))
		return NULL;
	while (++i < SIZE_Y)
	{
		//ft_printf("i : %d\n", i);	
		j = -1;
		while(++j < SIZE_X)
		{
			//ft_printf("j : %d", j);	
			if (rt_intersect(s.sphere.pos, map[i][j], s.sphere.rayon)){
				tab[i][j] = 1;
				//ft_printf("tab[i][j] avec i: %d, j: %d et tab ij: %d\n", i, j, tab[i][j]);
			}
			else
				tab[i][j] = 0;
		}
	}
	return (tab);
}
