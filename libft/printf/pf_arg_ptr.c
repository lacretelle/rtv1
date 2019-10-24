/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:35:19 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 14:48:54 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_print	pf_config_ptr(t_print p)
{
	p.conv = 'x';
	p.hash = 1;
	p.force_h = 1;
	p.modifier = T_L;
	return (p);
}

t_print			pf_arg_ptr(va_list ap, t_print p)
{
	p = pf_config_ptr(p);
	p = pf_arg_uint(ap, p);
	return (p);
}
