/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:57:12 by madufour          #+#    #+#             */
/*   Updated: 2019/03/20 14:01:47 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_mlx	rt_init_window(void)
{
	t_mlx	mlx;

	mlx.size_x = RTV1_W;
	mlx.size_y = RTV1_H;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.size_x, mlx.size_y, "mlx 42");
	mlx.img = mlx_new_image(mlx.mlx, mlx.size_x, mlx.size_y);
	mlx.data = (int*)mlx_get_data_addr(mlx.img, \
			&(mlx.bpp), &(mlx.size_line), &(mlx.endian));
	return (mlx);
}

int				main(int ac, char **av)
{
	char	name;
	t_mlx	mlx;

	mlx = rt_init_window();
	name = 0;
	if (ac == 2)
	{
	mlx_hook(mlx.win, 2, (1L >> 0), key, &mlx);
	mlx_hook(mlx.win, 4, (1L >> 0), mouse, &mlx);
	mlx_hook(mlx.win, 6, (1L >> 0), mouse_move, &mlx);
	mlx_hook(mlx.win, 5, (1L >> 0), mouse_release, &mlx);
	mlx_hook(mlx.win, 17, (1L >> 0), rt_close, &mlx);
	mlx_loop(mlx.mlx);
	}
	else
		ft_putendl_fd("Usage: ./fractol [ param ]", 2);
	return (0);
}
