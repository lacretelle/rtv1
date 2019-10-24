/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:35:19 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 18:21:36 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_base(uintmax_t n, t_print p)
{
	char	*buff;

	if (p.conv == 'o' || p.conv == 'O')
		buff = ft_ltoa(n, 8);
	else if (p.conv == 'u' || p.conv == 'U')
		buff = ft_ltoa(n, 10);
	else if (p.conv == 'x' || p.conv == 'X')
		buff = ft_ltoa(n, 16);
	else
		buff = NULL;
	return (buff);
}

static char	*add_upcase(char *buff)
{
	int		i;

	i = 0;
	while (buff[i] != '\0')
	{
		buff[i] = (char)ft_toupper((int)buff[i]);
		i++;
	}
	return (buff);
}

static char	*move_hash(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] == '0')
		i++;
	str[i] = '0';
	str[1] = 'x';
	return (str);
}

static char	*modif_buff_uint(char *buff, uintmax_t n, t_print p)
{
	if (p.precision == 0)
		buff = pf_check_val_zero_exception(buff, n);
	if (p.precision > (int)ft_strlen(buff))
		buff = pf_add_precision(buff, p);
	if (p.hash == 1 && ((p.force_h == 1 || n != 0) ||
				(p.conv != 'x' && p.conv != 'X')))
		buff = pf_add_hash(buff, p);
	if (p.size > (int)ft_strlen(buff))
	{
		buff = pf_add_size(buff, p, 1);
		if (p.hash == 1 && (p.conv == 'x' || p.conv == 'X')
				&& p.zero == 1 && (n != 0 || p.force_h == 1))
			buff = move_hash(buff);
	}
	if (p.conv == 'X')
		buff = add_upcase(buff);
	return (buff);
}

t_print		pf_arg_uint(va_list ap, t_print p)
{
	uintmax_t	var;
	char		*buff;

	p = pf_modifier_update(p);
	var = pf_va_arg_uint(ap, p);
	buff = get_base((uintmax_t)var, p);
	buff = modif_buff_uint(buff, var, p);
	p = pf_collapse_buff(buff, p);
	return (p);
}
