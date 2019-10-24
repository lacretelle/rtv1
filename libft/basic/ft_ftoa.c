/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:20:44 by cmaxime           #+#    #+#             */
/*   Updated: 2019/01/29 10:52:48 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ftoa_round(char *str, int n)
{
	int		l;
	int		val;

	if (n < 5)
		return (str);
	l = (int)ft_strlen(str) - 1;
	while (l >= 1)
	{
		val = str[l] - '0' + 1;
		if (10 + '0' != (str[l] = (char)val + '0'))
			return (str);
		str[l] = '0';
		l--;
	}
	return (str);
}

char			*ft_ftoa(double nb, int precision)
{
	char	*new;
	char	*buff;
	int		i;

	buff = ft_ltoa((uintmax_t)nb, 10);
	if (precision < 1)
		return (buff);
	new = ft_strnew((size_t)(precision + 1));
	new[0] = '.';
	i = 0;
	while (++i <= precision)
	{
		nb *= 10.;
		new[i] = (int)nb % 10 + '0';
	}
	new = ft_ftoa_round(new, (int)(nb * 10) % 10);
	new[i] = '\0';
	buff = ft_realloc(buff, new);
	free(new);
	return (buff);
}
