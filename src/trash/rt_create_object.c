/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_create_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:20:27 by madufour          #+#    #+#             */
/*   Updated: 2019/04/19 17:22:23 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Create maillon of list for each object in the scene
*/
#include "rtv1.h"

t_list		*rt_create_object(char *data, char *name)
{
	t_rtobject	obj;
	
	if (ft_strcmp(name, "camera") == 0)
		obj = rt_create_cam(obj, tmp[1]);
	else if (name == "sphere")
		obj = rt_create_sphere(tmp[1]);
	else if (name == "plan")
		obj = rt_create_plan(tmp[1]);
	else if (name == "cylinder")
		obj = rt_create_cy(tmp[1]);
	else if (name == "cone")
		obj = rt_create_cone(tmp[1]);
	return (ft_lstnew(&(void*)obj, sizeof(t_rtobject)));
}
