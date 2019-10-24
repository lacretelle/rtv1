/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_create_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:06:42 by madufour          #+#    #+#             */
/*   Updated: 2019/04/19 17:15:43 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		*rt_fill_tab(char *tmp)
{
	size_t	i;
	double	*tab;
	char	**tp;

	if (!(tp = ft_strsplit(tmp, ',')))
		return (0);
	i = 0;
	while (tp[i] != 0)
		i++;
	if (!(tab = (int*)malloc(siseof(int) * i)))
		return (0);
	i = 0;
	while (tp[i] != 0)
	{
		tab[i] = ft_atof(tp[i]);
		i++;
	}
	free(tp);
	return (tab);
}

//Gestion juste de l'origine a refaire pour rotation...
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

t_rtobject	rt_create_cam(t_rtobject obj, char *data)
{
	t_rtcamera	*objdata;
	size_t		i;
	double		*tab;

	obj.type = T_CAMERA;
	tab = rt_parse_data(data);
	if (objdata = (t_rtcamera*)ft_memalloc(sizeof(t_rtcamera)))
	{
		objdata->origin = ft_vectornew(3);
		i = 0;
		if (!(tab = rt_parse_data(data)))
			return (0);
		while (i < 3)
		{
			objdata->origin = ft_setvalvector(objdata->origin, tab[i], i);
			i++;
		}
	}
	obj.objdata = (void*)objdata;
	// verif si malloc doesnt work ?
	return (obj);
}
