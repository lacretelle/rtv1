/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_man_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:16:19 by madufour          #+#    #+#             */
/*   Updated: 2019/10/25 11:44:50 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_mlx	img_put_pxl(t_mlx mlx, int x, int y, int color)
{
	if (x < mlx.size_x && y < mlx.size_y && x >= 0 && y >= 0)
		mlx.data[x + y * mlx.size_line / 4] = color;
	return (mlx);
}

static t_mlx	rt_fill_img(t_mlx mlx, int **tab)
{
	int	i;
	int	j;
	(void)tab;

	i = -1;
	while (++i < SIZE_Y)
	{
		j = -1;
		while (++j < SIZE_X)
		{
			if (tab[i][j] == 0)
			{
				img_put_pxl(mlx, j, i, 0x000000);
			}
			else
			{
				//ft_printf("red");
				img_put_pxl(mlx, j, i, 0xff0000);
			}
		}
	}
	return (mlx);
}

/*
 * Fucntion for clear the image
 * @return t_mlx structure initialize with 0
*/
static t_mlx	rt_clear_img(t_mlx mlx)
{
	int	size;
	int	i;

	size = mlx.size_x * mlx.size_y;
	i = -1;
	while (++i < size && size > 0)
		mlx.data[i] = 0;
	return (mlx);
}

/*
 * Function for generate and manage image from an array of vector (ray prim of scene)
 * @return a t_mlx structure 
 */
t_mlx	rt_man_img(t_mlx mlx, int **tab)
{
	mlx = rt_clear_img(mlx);
	mlx = rt_fill_img(mlx, tab);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	return (mlx);
}
