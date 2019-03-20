/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:28:46 by madufour          #+#    #+#             */
/*   Updated: 2018/11/20 10:40:50 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nb, char *base)
{
	long	n;
	size_t	size;
	int		cmp;

	n = (long)nb;
	size = ft_strlen(base);
	cmp = (int)size;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n >= cmp)
	{
		ft_putnbr_base(n / size, base);
		ft_putnbr_base(n % size, base);
	}
	if (n >= 0 && n < cmp)
		ft_putchar(base[n]);
}
