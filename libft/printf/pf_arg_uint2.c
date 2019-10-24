/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_uint2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:53:57 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 18:21:34 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_get_hexa_htag(void)
{
	char	*new;

	new = ft_strnew(2);
	new[0] = '0';
	new[1] = 'x';
	return (new);
}

char	*pf_get_octa_htag(void)
{
	char	*new;

	new = ft_strnew(1);
	new[0] = '0';
	return (new);
}

char	*pf_add_hash(char *buff, t_print p)
{
	char	*new;

	if (p.conv == 'x' || p.conv == 'X')
	{
		new = ft_realloc(pf_get_hexa_htag(), buff);
		free(buff);
	}
	else if (p.conv == 'o' || p.conv == 'O')
	{
		if (buff[0] == '0')
			new = buff;
		else
		{
			new = ft_realloc(pf_get_octa_htag(), buff);
			free(buff);
		}
	}
	else
		new = buff;
	return (new);
}
