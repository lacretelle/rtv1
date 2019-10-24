/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_core_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:36:48 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 15:48:12 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			pf_cmpchr(char *list, char c)
{
	int		i;

	i = 0;
	while (list[i] != '\0')
	{
		if ((unsigned char)list[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

static int	update_ret(int ret, int *pos, char *str)
{
	char	**list;
	int		buff;

	list = pf_get_list_flag();
	buff = 0;
	while (ret > 0 && buff == 0)
	{
		buff = pf_cmpchr(list[ret - 1], str[*pos]);
		if (buff == 0)
			ret--;
	}
	if (ret == 0)
	{
		*pos += 1;
		return (ret);
	}
	*pos += 1;
	if (ret == 4 || ret == 1)
		ret -= 1;
	return (ret);
}

t_print		pf_extractflag(char *str, int *i, t_print p)
{
	int		pos;
	int		ret;

	pos = 1;
	ret = 7;
	while (ret > 0)
	{
		ret = update_ret(ret, &pos, str);
	}
	p = pf_update_t_print(str, pos, p);
	*i += pos;
	return (p);
}
