/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:17:43 by cmaxime           #+#    #+#             */
/*   Updated: 2019/01/23 17:17:45 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_powof(double nb, int exp)
{
	double	result;
	int		i;

	i = -1;
	result = 1.;
	if (exp >= 0)
	{
		while (++i < exp)
			result *= nb;
	}
	else
	{
		while (++i < -exp)
			result *= 1. / nb;
	}
	return (result);
}
