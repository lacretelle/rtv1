/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wchar_to_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:58:39 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/22 16:16:34 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_wchar(wchar_t wc)
{
	int		size;

	size = 1;
	if ((wc / ft_pow(2, 7) == 0))
		return (size);
	size++;
	while (wc / ft_pow(2, 1 + 5 * size) > 0)
	{
		size++;
	}
	return (size);
}

static char	*get_normalchar(char *new, wchar_t wc)
{
	new[0] = (char)wc;
	return (new);
}

static char	*set_utfstr(char *new, int size)
{
	unsigned char	c;

	c = (unsigned char)new[0];
	if (size == 2)
		new[0] = (char)((c & 0x1F) | 0xC0);
	if (size == 3)
		new[0] = (char)((c & 0x0F) | 0xE0);
	if (size == 4)
		new[0] = (char)((c & 0x07) | 0xF0);
	return (new);
}

static char	*get_formatedchar(char *new, wchar_t wc, int size)
{
	int		i;

	i = 1;
	while (size--)
	{
		new[size] = (char)(((wc >> 6 * (i - 1)) & 0x3F) | 0x80);
		i++;
	}
	new = set_utfstr(new, i - 1);
	return (new);
}

char		*pf_wchar_to_char(wchar_t wc, int *lenght)
{
	char	*new;
	int		size;

	size = size_wchar(wc);
	if (MB_CUR_MAX == 1)
		size = 1;
	new = ft_strnew((size_t)size);
	if (size == 1)
		new = get_normalchar(new, wc);
	else
		new = get_formatedchar(new, wc, size);
	*lenght = size;
	return (new);
}
