/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:15:20 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/22 17:41:38 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print		pf_op_size(char *str, int *i, t_print p)
{
	p.size = ft_atoi(str + *i);
	while (ft_isdigit(str[*i]))
		*i += 1;
	return (p);
}

t_print		pf_op_precision(char *str, int *i, t_print p)
{
	*i += 1;
	p.precision = ft_atoi(str + *i);
	while (ft_isdigit(str[*i]))
		*i += 1;
	return (p);
}

t_print		pf_op_modifier(char *str, int *i, t_print p)
{
	int		r;
	int		b;

	r = 0;
	while (pf_cmpchr("hljz", str[r + *i]) == 1)
		r++;
	b = r;
	while (--r >= 0)
	{
		if (str[*i + r] == 'j')
			p.modifier = T_J;
		else if (str[*i + r] == 'z' && p.modifier < T_Z)
			p.modifier = T_Z;
		else if (str[*i + r] == 'l' && p.modifier < T_L)
			p.modifier = T_L;
		else if (str[*i + r] == 'h' && p.modifier < T_H)
			p.modifier = T_H;
		else if (str[*i + r] == 'l' && (p.modifier < T_LL || p.modifier == T_L))
			p.modifier = T_LL;
		else if (str[*i + r] == 'h' && (p.modifier < T_HH || p.modifier == T_H))
			p.modifier = T_HH;
	}
	*i += b;
	return (p);
}

t_print		pf_op_conv(char *str, int *i, t_print p)
{
	p.conv = str[*i];
	*i += 1;
	return (p);
}
