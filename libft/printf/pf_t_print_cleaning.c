/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_t_print_cleaning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:49:17 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 16:06:36 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_print	pf_modifier_upcase(t_print p)
{
	if (p.conv >= 'A' && p.conv <= 'Z')
	{
		if (p.conv != 'X')
			p.modifier = T_L;
	}
	return (p);
}

static t_print	pf_zero(t_print p)
{
	if ((p.precision != -1 && pf_cmpchr("dDioOuUxX", p.conv) == 1)
			|| p.minus == 1)
		p.zero = 0;
	return (p);
}

static t_print	pf_space(t_print p)
{
	if (p.plus == 1)
		p.space = 0;
	return (p);
}

t_print			pf_modifier_update(t_print p)
{
	p = pf_modifier_upcase(p);
	p = pf_zero(p);
	p = pf_space(p);
	return (p);
}
