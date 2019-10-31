/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:21:46 by madufour          #+#    #+#             */
/*   Updated: 2019/10/25 11:33:08 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*POINTS APPARTENANT A LA DEMI DROITE QUI A UNE ORIGINE ET UN VECTEUR DIRECTEUR*/
//(x, y, z) = (ox, oy, oz) + (vecx, vecy, vecz) * t avec t > 0

t_scene rt_initscene(void)
{
	t_scene	scene;
	static	t_vec3	direction = {0, 0, 1};
	static	t_vec3	pos = {0, 10, 20};
	
	ft_bzero(&(scene.camera), sizeof(t_rtcamera));
	ft_memcpy(scene.camera.dir, direction, sizeof(t_vec3));
	scene.camera.f = 10;
	scene.camera.height = 20;
	scene.camera.width = 40;

    ft_bzero(&(scene.sphere), sizeof(t_rtsphere));
	ft_memcpy(scene.sphere.pos, pos, sizeof(t_vec3));
    scene.sphere.rayon = 10;
    scene.sphere.color = 0x00ff0000;
    return (scene);
}

/*FICHIER A METTRE A PART MLX INIT*/

t_mlx	rt_initmlx(void)
{
	t_mlx	mlx;

	mlx.size_x = SIZE_X;
	mlx.size_y = SIZE_Y;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.size_x, mlx.size_y, "mlx 42");
	mlx.img = mlx_new_image(mlx.mlx, mlx.size_x, mlx.size_y);
	mlx.data = (int*)mlx_get_data_addr(mlx.img, &(mlx.bpp), &(mlx.size_line), &(mlx.endian));
	return (mlx);
}
int     main(int ac, char *av[])
{
    t_scene	scene;
	t_mlx	mlx;
	t_vec3	p;
	t_vec3	**map;
	int		**tab;
	double	kw;
	double	kh;
	(void)ac;
	(void)av;

	mlx = rt_initmlx();
   	scene = rt_initscene();
	//tableau contenant les rayons primaires de chaque pixel=> z restera le meme
	p[0] = scene.camera.width / 2.0;
	p[1] = scene.camera.height / 2.0;
	p[2] = scene.camera.f;
	kw = mlx.size_x / scene.camera.width;
	kh = mlx.size_y / scene.camera.height;
	if (!(map = rt_rayprim(p, kw, kh)))
	{
		//clear scene
		ft_putendl_fd("Usage: An error occured.", 2);
		return (1);
	}
	else
	{
		ft_printf("All it's OK!\n");
		ft_printf("kw : %f \n", kw);
		ft_printf("kh : %f \n", kh);
		ft_printf("r in Main: %f\n", scene.sphere.rayon);
		tab = search_intersect(scene, map);
	}
	if (tab)
		rt_man_img(mlx, tab);
	// printmap(map);

	//load_scene_from_file("scenes/scene1");
	mlx_loop(mlx.mlx);
    return (0);
}
