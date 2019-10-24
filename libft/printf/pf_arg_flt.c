/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:35:19 by cmaxime           #+#    #+#             */
/*   Updated: 2019/01/25 17:24:39 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*add_signe(char *buff, int signe)
{
	char	*new;

	new = ft_strnew(ft_strlen(buff) + 1);
	new[0] = '+';
	if (signe < 0)
		new[0] = '-';
	new = ft_strcat(new, buff);
	free(buff);
	return (new);
}

static char		*add_space(char *buff)
{
	char	*new;

	new = ft_strnew(ft_strlen(buff) + 1);
	new[0] = ' ';
	new = ft_strcat(new, buff);
	free(buff);
	return (new);
}

static char		*process_hash(char *buff)
{
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '.')
		i++;
	if (buff[i] == '\0')
		return (buff);
	while (buff[i])
		i++;
	while (buff[--i] == '0')
		buff[i] = '\0';
	if (buff[i] == '.')
		buff[i] = '\0';
	return (buff);
}

static char		*modif_buff_flt(char *buff, int signe, uintmax_t n, t_print p)
{
	if (p.precision == 0)
		buff = pf_check_val_zero_exception(buff, n);
	if (p.precision > (int)ft_strlen(buff))
		buff = pf_add_precision(buff, p);
	if (p.plus == 1 || signe < 0)
		buff = add_signe(buff, signe);
	if (p.space == 1 && signe > 0)
		buff = add_space(buff);
	if (p.hash == 1)
		buff = process_hash(buff);
	if (p.size > (int)ft_strlen(buff))
		buff = pf_add_size(buff, p, -1);
	return (buff);
}

t_print			pf_arg_flt(va_list ap, t_print p)
{
	double		var;
	char		*buff;
	int			signe;

	p = pf_modifier_update(p);
	var = pf_va_arg_dec(ap, p);
	signe = (double)var >= 0 ? 1 : -1;
	buff = ft_ftoa(var * (double)signe, p.precision != -1 ? p.precision : 6);
	buff = modif_buff_flt(buff, signe, (uintmax_t)var, p);
	p = pf_collapse_buff(buff, p);
	return (p);
}
