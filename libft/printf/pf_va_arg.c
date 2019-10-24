/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_va_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:34:47 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/22 17:54:45 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		pf_va_arg_dec(va_list ap, t_print p)
{
	double	new;

	(void)p;
	new = va_arg(ap, double);
	return (new);
}

uintmax_t	pf_va_arg_int(va_list ap, t_print p)
{
	uintmax_t	new;

	if (p.modifier == T_J)
		new = (uintmax_t)va_arg(ap, uintmax_t);
	else if (p.modifier == T_Z)
		new = (uintmax_t)(ssize_t)va_arg(ap, ssize_t);
	else if (p.modifier == T_L)
		new = (uintmax_t)(long)va_arg(ap, long);
	else if (p.modifier == T_H)
		new = (uintmax_t)(short)va_arg(ap, int);
	else if (p.modifier == T_LL)
		new = (uintmax_t)(long long)va_arg(ap, long);
	else if (p.modifier == T_HH)
		new = (uintmax_t)(char)va_arg(ap, int);
	else
		new = (uintmax_t)(int)va_arg(ap, int);
	return (new);
}

uintmax_t	pf_va_arg_uint(va_list ap, t_print p)
{
	uintmax_t	new;

	if (p.modifier == T_J)
		new = (uintmax_t)va_arg(ap, uintmax_t);
	else if (p.modifier == T_Z)
		new = (size_t)va_arg(ap, size_t);
	else if (p.modifier == T_L)
		new = (unsigned long)va_arg(ap, unsigned long);
	else if (p.modifier == T_H)
		new = (unsigned short)va_arg(ap, unsigned int);
	else if (p.modifier == T_LL)
		new = (unsigned long long)va_arg(ap, unsigned long);
	else if (p.modifier == T_HH)
		new = (unsigned char)va_arg(ap, unsigned int);
	else
		new = (unsigned int)va_arg(ap, unsigned int);
	return (new);
}

wchar_t		pf_va_arg_chr(va_list ap)
{
	wchar_t	wc;

	wc = (wchar_t)va_arg(ap, wchar_t);
	return (wc);
}

void		*pf_va_arg_ptr(va_list ap, t_print p)
{
	void	*ptr;

	if (p.conv == 's' || p.conv == 'S')
	{
		if (p.modifier == T_L)
			ptr = (wchar_t*)va_arg(ap, wchar_t*);
		else
			ptr = (char*)va_arg(ap, char*);
	}
	else
		ptr = va_arg(ap, void*);
	return (ptr);
}
