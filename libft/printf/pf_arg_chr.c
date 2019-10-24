/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:35:19 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/22 16:19:20 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		pf_check_mb_cur_max(void)
{
	if (MB_CUR_MAX == 1)
		return (255);
	if (MB_CUR_MAX == 2)
		return (0x7FF);
	if (MB_CUR_MAX == 3)
		return (0xFFFF);
	if (MB_CUR_MAX == 4)
		return (0x10FFFF);
	return (0);
}

static char	*chr_error_manager(t_print *p)
{
	p->ret = -1;
	return (NULL);
}

static char	*modif_buff_chr(wchar_t wc, int *lenght, t_print *p)
{
	char	*buff;

	if (wc > pf_check_mb_cur_max() || ((wc < 0 || (wc >= 0xd800 &&
						wc < 0xE000)) && p->modifier == T_L))
		return (chr_error_manager(p));
	buff = pf_wchar_to_char((wchar_t)wc, lenght);
	if (p->size > *lenght)
		buff = pf_add_size_chr(buff, lenght, *p);
	return (buff);
}

t_print		pf_arg_chr(va_list ap, t_print p)
{
	int		var;
	char	*buff;
	int		lenght;

	lenght = 0;
	if (p.modifier != T_L || p.modifier != T_LL)
		p.modifier = T_HH;
	if (p.modifier == T_LL)
		p.modifier = T_L;
	p = pf_modifier_update(p);
	var = pf_va_arg_chr(ap);
	buff = modif_buff_chr((wchar_t)var, &lenght, &p);
	p = pf_collapse_char(buff, lenght, p);
	return (p);
}
