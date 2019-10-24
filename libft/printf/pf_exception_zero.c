/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_exception_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:26:42 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 14:51:50 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_check_val_zero_exception(char *buff, uintmax_t n)
{
	if (n == 0)
	{
		free(buff);
		buff = ft_strnew(0);
	}
	return (buff);
}
