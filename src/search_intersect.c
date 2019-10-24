/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:50:55 by madufour          #+#    #+#             */
/*   Updated: 2019/10/22 14:32:37 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double dot_product(t_vec3 v, t_vec3 u)
{
	double res;
	int i;

	res = 0.0;
	i = -1;
	while (++i < 3)
		res += v[i] * u[i];
	return res;
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
		return 1;
	else
		return 0;
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

	(void)r;
	a = dot_product(v2, v2);
	b = 2 * dot_product(v1, v2);
	c = dot_product(v1, v1) - (r * r);
	ft_printf("a: %f, b: %f , c: %f\n", a,b,c);
	delta = b * b - 4 * a * c;
	ft_printf("delta: %f\n", delta);
	if (delta < 0)
		return 1;
	else
		return 0;
	/*d2 = dot_product(v1, v1) - tca * tca;
	ft_printf("r  %f, ", r);
	ft_printf(" d2  %f\n", d2);
	if (d2 > (r * r))
		return 0;
	else
		return 1;*/
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

int	**search_intersect(t_scene s, t_vec3 **map)
{
	int		**tab;
	size_t	i;
	size_t	j;
	size_t	o;

	(void)map;
	//calcul pour chaque pixel if intersect or not
	// CH^2 = OC^2 - OH^2
	i = -1;
	o = s.sphere.rayon;
	if (!(tab = rt_init_tab()))
		return NULL;
	while (++i < SIZE_Y)
	{
		ft_printf("i : %d\n", i);	
		j = -1;
		while(++j < SIZE_X)
		{
			//ft_printf("j : %d", j);	
			if (rt_intersect(s.sphere.pos, map[i][j], s.sphere.rayon))
				tab[i][j] = 1;
			else
				tab[i][j] = 0;
		}
	}
	return (tab);
}
