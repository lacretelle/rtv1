/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:54:43 by cmaxime           #+#    #+#             */
/*   Updated: 2019/04/09 14:44:06 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		buff;

	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			n = 147483648;
			ft_putchar('2');
		}
		else
			n = -1 * n;
	}
	if (n > 9)
	{
		buff = n % 10 + 48;
		ft_putnbr(n / 10);
		ft_putchar((char)buff);
	}
	else
	{
		buff = n + 48;
		ft_putchar((char)buff);
	}
}
