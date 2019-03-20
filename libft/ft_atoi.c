/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:35:43 by madufour          #+#    #+#             */
/*   Updated: 2018/11/13 19:20:09 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		signe;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
	|| str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (res * signe);
}
