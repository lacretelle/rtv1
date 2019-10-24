/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:31:40 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/21 16:06:38 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*add_size_signe(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0' && str[i] == '0')
		i++;
	if (str[i] == '+' || str[i] == ' ' || str[i] == '-')
	{
		c = str[i];
		str[i] = '0';
		str[0] = c;
	}
	return (str);
}

char		*pf_add_size(char *buff, t_print p, int signe)
{
	int		n;
	char	*new;
	char	c;

	c = ' ';
	if (p.zero == 1)
		c = '0';
	n = p.size - (int)ft_strlen(buff);
	new = ft_strnew((size_t)n);
	while (n-- > 0)
		new[n] = c;
	if (p.minus == 1)
	{
		buff = ft_realloc(buff, new);
		free(new);
	}
	else
	{
		new = ft_realloc(new, buff);
		free(buff);
		buff = new;
	}
	if (signe < 0 && c == '0')
		buff = add_size_signe(buff);
	return (buff);
}

char		*pf_add_size_chr(char *buff, int *lenght, t_print p)
{
	int		n;
	char	*new;
	char	c;

	c = p.zero == 1 ? '0' : ' ';
	n = p.size - *lenght;
	new = ft_strnew((size_t)n);
	while (n-- > 0)
		new[n] = c;
	if (p.minus == 1)
	{
		buff = ft_realloc_mem(buff, new, (size_t)(*lenght),
				(size_t)(p.size - *lenght));
		free(new);
	}
	else
	{
		new = ft_realloc_mem(new, buff, (size_t)(p.size - *lenght),
				(size_t)*lenght);
		free(buff);
		buff = new;
	}
	*lenght = p.size;
	return (buff);
}
