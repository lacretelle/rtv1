/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_create_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:29:26 by madufour          #+#    #+#             */
/*   Updated: 2019/04/19 17:31:10 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		*rt_parse_data(char *data)
{
	double	*tab;
	char	*tmp;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (data[i] != '(')
		i++;
	while (data[i + k] != ')')
		k++;
	if (!(tmp = ft_strsub(data, i + 1, k)))
		return (0);
	if (!(tab = rt_fill_tab(tmp)))
		return (0);
	free(tmp);
	return (tab);
}

t_rtobject	rt_create_sphere(t_rtobject obj, char *data)
{
	t_rtsphere	*objdata;
	size_t		i;
	double		*tab;

	obj.type = T_CAMERA;
	tab = rt_parse_data(data);
	if (objdata = (t_rtsphere*)ft_memalloc(sizeof(t_rtsphere)))
	{
		objdata->origin = ft_vectornew(3);
		i = 0;
		if (!(tab = rt_parse_data(data)))
			return (0);
		while (i < 3)
		{
			objdata->ray = ft_setvalvector(objdata->origin, tab[i], i);
			i++;
		}
	}
	obj.objdata = (void*)objdata;
}
