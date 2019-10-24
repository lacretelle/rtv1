/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:44:01 by cmaxime           #+#    #+#             */
/*   Updated: 2019/01/29 10:37:20 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	double	nb;
	double	f;
	int		i;

	nb = (double)(ft_atoi(str));
	i = 0;
	while (str[i] && ft_in(str[i], "0123456789"))
		i++;
	if (str[i] != '.')
		return (nb);
	i++;
	while (str[i] && ft_in(str[i], "0123456789"))
		i++;
	f = 0;
	while (str[--i] && ft_in(str[i], "0123456789"))
		f = (f + (double)(str[i] - '0')) / 10.;
	return (nb + f);
}
