/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:30:27 by madufour          #+#    #+#             */
/*   Updated: 2018/11/13 19:18:48 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*src;
	unsigned char	*str;

	i = 0;
	src = (unsigned char*)s1;
	str = (unsigned char*)s2;
	while (src[i] == str[i] && str[i] != '\0')
		i++;
	return (src[i] - str[i]);
}
