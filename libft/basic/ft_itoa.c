/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:41:13 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/14 16:02:56 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_sizenb(int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*new;
	size_t	size;
	int		mod;

	size = get_sizenb(n);
	new = ft_strnew(size);
	mod = 1;
	if (!new)
		return (new);
	if (n == 0)
		new[0] = '0';
	if (n < 0)
	{
		new[0] = '-';
		mod = -1;
	}
	while (n != 0)
	{
		size--;
		new[size] = (char)(mod * (n % 10) + 48);
		n = n / 10;
	}
	return (new);
}
