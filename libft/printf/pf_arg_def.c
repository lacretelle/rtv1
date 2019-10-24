/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:35:19 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 15:59:12 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_print	pf_blank_space(t_print p)
{
	char	*new;

	new = ft_strnew(1);
	new[0] = p.conv;
	if (p.size != 0)
		new = pf_add_size(new, p, 0);
	p = pf_collapse_buff(new, p);
	return (p);
}

t_print			pf_arg_def(va_list ap, t_print p)
{
	(void)ap;
	p = pf_blank_space(p);
	return (p);
}
