/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:56:26 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 14:52:18 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_base(size_t base)
{
	static char	*bases[4] = {
		"01",
		"01234567",
		"0123456789abcdef",
		"0123456789"
	};

	if (base == 2)
		return (bases[0]);
	if (base == 8)
		return (bases[1]);
	if (base == 16)
		return (bases[2]);
	return (bases[3]);
}

static size_t	get_sizenb(uintmax_t n, size_t base)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}

char			*ft_ltoa(uintmax_t n, size_t base)
{
	char	*new;
	size_t	size;
	char	*str_base;

	str_base = get_base(base);
	size = get_sizenb(n, base);
	new = ft_strnew(size);
	if (!new)
		return (new);
	if (n == 0)
		new[0] = '0';
	while (n != 0)
	{
		size--;
		new[size] = str_base[n % base];
		n = n / base;
	}
	return (new);
}
