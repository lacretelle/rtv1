/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:57:05 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 14:53:00 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_add_precision(char *buff, t_print p)
{
	char	*new;
	int		diff;

	new = ft_strnew((size_t)p.precision);
	diff = p.precision - (int)ft_strlen(buff);
	while (diff-- > 0)
		new[diff] = '0';
	new = ft_strcat(new, buff);
	free(buff);
	return (new);
}
