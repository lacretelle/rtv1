/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:15:07 by cmaxime           #+#    #+#             */
/*   Updated: 2018/01/16 19:08:41 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print			pf_update_t_print(char *str, int pos, t_print p)
{
	int		i;
	int		r;
	t_op	*lst;

	lst = pf_get_op();
	i = 1;
	while (i < pos)
	{
		r = 0;
		while (r < 8 && pf_cmpchr(lst[r].op, str[i]) == 0)
		{
			r++;
		}
		p = lst[r].f(str, &i, p);
	}
	return (p);
}

static t_print	process_str(char *fmt, int *i, t_print p)
{
	while (fmt[*i] != '%' && fmt[*i] != '\0')
	{
		if (p.pib >= 100)
			p = pf_flush_buff(p);
		p.buff[p.pib] = fmt[*i];
		p.pib++;
		p.ret++;
		*i += 1;
	}
	return (p);
}

static t_print	process_flag(char *fmt, int *i, va_list ap, t_print p)
{
	t_cnv	*cnv;
	int		r;

	p = pf_extractflag(fmt + *i, i, p);
	cnv = pf_get_cnv();
	r = 0;
	while (r < 6 && pf_cmpchr(cnv[r].cnv, p.conv) == 0)
		r++;
	p = cnv[r].f(ap, p);
	return (p);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	t_print	p;

	p = pf_init_t_print();
	va_start(ap, format);
	i = 0;
	while (format[i] != '\0' && p.ret >= 0)
	{
		if (format[i] == '%')
		{
			p = process_flag((char*)(uintptr_t)format, &i, ap, p);
			if (p.conv == '\0')
				i--;
			p = pf_reinit_t_print(p);
		}
		else
			p = process_str((char*)(uintptr_t)format, &i, p);
	}
	p = pf_output_buff(p);
	return (p.ret);
}
