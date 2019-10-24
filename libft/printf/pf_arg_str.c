/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:35:19 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/22 17:04:37 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_error_manager(t_print *p, char *buff)
{
	buff[0] = '\0';
	p->ret = -1;
	return (buff);
}

static char	*pf_wchar_str(wchar_t *var, t_print *p)
{
	char	*buff;
	char	*wc;
	int		i;
	int		lenght;
	int		prec;

	prec = p->precision;
	i = -1;
	buff = ft_strnew(0);
	while (var[++i] != 0 && prec != 0)
	{
		if (var[i] > pf_check_mb_cur_max() || ((var[i] < 0 || (var[i] >= 0xD800
							&& var[i] < 0xE000)) && p->modifier == T_L))
			return (str_error_manager(p, buff));
		wc = pf_wchar_to_char(var[i], &lenght);
		if (p->precision != -1 && (prec = prec - lenght) < 0)
		{
			free(wc);
			return (buff);
		}
		buff = ft_realloc(buff, wc);
		free(wc);
	}
	return (buff);
}

static char	*pf_char_str(void *var, t_print p)
{
	char	*buff;

	if ((int)ft_strlen(var) > p.precision && p.precision != -1)
		buff = ft_strsub((char*)var, 0, (size_t)p.precision);
	else
		buff = ft_strdup(var);
	return (buff);
}

t_print		pf_arg_str(va_list ap, t_print p)
{
	void	*var;
	char	*buff;

	p = pf_modifier_update(p);
	var = pf_va_arg_ptr(ap, p);
	if (var == 0)
	{
		buff = p.precision < 6 && p.precision != -1 ?
			ft_strsub("(null)", 0, (size_t)p.precision) : ft_strdup("(null)");
	}
	else if (p.modifier == T_L)
		buff = pf_wchar_str((wchar_t*)var, &p);
	else
		buff = pf_char_str(var, p);
	if (p.ret != -1 && (int)ft_strlen(buff) < p.size)
		buff = pf_add_size(buff, p, 0);
	p = pf_collapse_buff(buff, p);
	return (p);
}
