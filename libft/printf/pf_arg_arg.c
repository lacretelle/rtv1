/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:35:19 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 14:47:09 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print	pf_arg_arg(va_list ap, t_print p)
{
	char	*buff;

	(void)ap;
	p = pf_modifier_update(p);
	buff = ft_strdup("%");
	if (p.size > 1)
		buff = pf_add_size(buff, p, 0);
	p = pf_collapse_buff(buff, p);
	return (p);
}
