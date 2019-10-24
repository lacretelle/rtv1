/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_collapse_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:23:45 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/22 17:54:44 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print		pf_output_buff(t_print p)
{
	if (p.ret == -1)
		p.pib = p.prev;
	write(1, p.buff, (size_t)p.pib);
	free(p.buff);
	return (p);
}

t_print		pf_flush_buff(t_print p)
{
	char	*new;

	new = ft_strnew(1000);
	p.buff = ft_realloc_mem(p.buff, new, (size_t)p.len, 1000);
	p.len += 1000;
	return (p);
}

t_print		pf_collapse_char(char *str, int lenght, t_print p)
{
	int		i;

	i = 0;
	while (i < lenght)
	{
		if (p.pib >= p.len)
			p = pf_flush_buff(p);
		p.buff[p.pib] = str[i];
		p.pib++;
		p.ret++;
		i++;
	}
	if (p.ret != -1)
		p.prev = p.pib;
	free(str);
	return (p);
}

t_print		pf_collapse_buff(char *str, t_print p)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (p.pib >= p.len)
			p = pf_flush_buff(p);
		p.buff[p.pib] = str[i];
		p.pib++;
		p.ret++;
		i++;
	}
	if (p.ret != -1)
		p.prev = p.pib;
	free(str);
	return (p);
}
