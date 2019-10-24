/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init_t_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:14:32 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 15:47:07 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print		pf_reinit_t_print(t_print p)
{
	p.force_h = 0;
	p.hash = 0;
	p.plus = 0;
	p.minus = 0;
	p.zero = 0;
	p.space = 0;
	p.size = 0;
	p.precision = -1;
	p.modifier = T_NONE;
	p.conv = '\0';
	return (p);
}

t_print		pf_init_t_print(void)
{
	t_print		new;

	new.prev = 0;
	new.len = 100;
	new.buff = ft_strnew((size_t)new.len);
	new.pib = 0;
	new.ret = 0;
	new = pf_reinit_t_print(new);
	return (new);
}
