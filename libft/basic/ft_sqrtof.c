/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:19:51 by cmaxime           #+#    #+#             */
/*   Updated: 2019/01/24 18:08:01 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sqrtof_step(long n, long p)
{
	int		x;

	p *= 20;
	x = 0;
	while ((p + x) * x < n && n >= (p + x + 1) * (x + 1))
		x++;
	return (x);
}

static double	ft_sqrtof_floating(long p, int indice)
{
	double	result;

	result = (double)p / ft_powof(10, indice);
	return (result);
}

static int		ft_sqrtof_indice(double nb)
{
	int		i;

	i = 0;
	if (nb >= 1)
	{
		while (nb > ft_powof(10, (i + 1) * 2))
			i++;
	}
	else
	{
		i = -1;
		while (nb < ft_powof(10, i * 2))
			i--;
	}
	return (i);
}

double			ft_sqrtof(double nb, size_t precision)
{
	int		indice;
	long	n;
	long	p;
	int		x;

	indice = ft_sqrtof_indice(nb);
	nb = nb / ft_powof(10, (indice * 2));
	p = 0;
	indice = (int)precision - indice;
	while (precision-- > 0 & nb > 10e-5)
	{
		n = ft_round(nb);
		x = ft_sqrtof_step(n, p);
		nb = (nb - (double)((p * 20 + x) * x)) * 100.;
		p = p * 10 + x;
	}
	return (ft_sqrtof_floating(p, indice - (int)precision - 2));
}
