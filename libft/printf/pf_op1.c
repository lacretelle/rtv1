/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_op1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:15:20 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 14:52:37 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print		pf_op_hash(char *str, int *i, t_print p)
{
	(void)str;
	p.hash = 1;
	*i += 1;
	return (p);
}

t_print		pf_op_zero(char *str, int *i, t_print p)
{
	(void)str;
	p.zero = 1;
	*i += 1;
	return (p);
}

t_print		pf_op_space(char *str, int *i, t_print p)
{
	(void)str;
	p.space = 1;
	*i += 1;
	return (p);
}

t_print		pf_op_min(char *str, int *i, t_print p)
{
	(void)str;
	p.minus = 1;
	*i += 1;
	return (p);
}

t_print		pf_op_plus(char *str, int *i, t_print p)
{
	(void)str;
	p.plus = 1;
	*i += 1;
	return (p);
}
