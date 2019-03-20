/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:59:23 by madufour          #+#    #+#             */
/*   Updated: 2018/11/19 15:38:31 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_scrib(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long nb;

	nb = (long)n;
	if (nb < 0)
	{
		ft_scrib('-', fd);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb >= 0 && nb <= 9)
		ft_scrib(nb + 48, fd);
}
