/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:29:54 by madufour          #+#    #+#             */
/*   Updated: 2018/11/19 15:37:48 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_char(long n)
{
	int count;

	count = 0;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	if (n >= 0 && n <= 9)
		count++;
	return (count);
}

static char	ft_putfill(long *s)
{
	long	n;
	char	c;

	n = *s;
	c = 0;
	if (n >= 0 && n <= 9)
		c = n + 48;
	if (n > 9)
	{
		c = (n % 10) + 48;
		n = n / 10;
		*s = n;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	long	nb;
	int		size;
	char	*res;
	int		signe;

	nb = (long)n;
	size = 0;
	signe = 1;
	if (nb < 0)
	{
		nb *= -1;
		signe = -1;
	}
	size = ft_size_char(nb);
	if (signe == -1)
		size += 1;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	if (signe == -1)
		res[0] = '-';
	size--;
	while ((size >= 0 && signe == 1) || (size > 0 && signe == -1))
		res[size--] = ft_putfill(&nb);
	return (res);
}
