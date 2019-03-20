/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:41:36 by madufour          #+#    #+#             */
/*   Updated: 2018/11/19 15:38:13 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_scribe(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int n)
{
	long nb;

	nb = (long)n;
	if (nb < 0)
	{
		ft_scribe('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
		ft_scribe(nb + 48);
}
