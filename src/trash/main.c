/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 10:42:07 by madufour          #+#    #+#             */
/*   Updated: 2019/04/19 15:27:28 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_list	*rt_create_lst(char **tab)
{
	int		i;
	char	**tmp;
	t_list	*new;
	t_list	*list;

	//Verif de la scene ?
	i = 0;
	//[camera ...] 0
	//[object ...] 1
	while (tab[i] != NULL)
	{
		tmp = ft_strsplit(tab[i], ':');

		new = rt_create_object(tmp[1], tmp[0]);
		/*if (tmp[0] == "camera")
			new = rt_create_cam(tmp[1], 1);
		else if (tmp[0] == "sphere")
			new = rt_create_sphere(tmp[1], 3);
		else if (tmp[0] == "plan")
			new = rt_create_plan(tmp[1], 2);
		else if (tmp[0] == "cylinder")
			new = rt_create_cy(tmp[1], 4);
		else if (tmp[0] == "cone")
			new = rt_create_cone(tmp[1], 5);
		*/
		i++;
		if (!(list))
			list = new;
		else
			ft_lstadd(&list, new);
		free(tmp);
		free(new);
	}
	return (list);
}

int     main(int ac, char *av[])
{
	char	**tab;
	t_list	*list;
	//split avec \n
	if (ac == 2)
	{
		tab = ft_strsplit(av[1], '\n');
		// creation de la liste avec camera et object
		list = rt_create_lst(tab);
	}
	else
	{
		ft_putendl("Usage: ./rtv1 [ param ]", 2);
		return (1);
	}
}
//recuperer scene et objets
//chaque objet sera un maillon
//en fonction de enum appeler bonne fonction qui crera maillon
