/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:23:25 by madufour          #+#    #+#             */
/*   Updated: 2018/11/16 11:04:30 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (n == 0)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i++;
	if (i == n || (s1[i] == s2[i] && s1[i] == '\0'))
		return (1);
	return (0);
}
