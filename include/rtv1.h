/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:15:10 by madufour          #+#    #+#             */
/*   Updated: 2019/10/22 13:52:11 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# define SIZE_X 200
# define SIZE_Y 80

typedef double	t_vec3[3];
typedef double	t_mat4[4][4];

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		*data;
	int		size_x;
	int		size_y;
}				t_mlx;

/*
** enum: Type indentifier of object in rt/
typedef enum	e_rttype
{
	T_NONE = 0,
	T_CAMERA,
	T_PLAN,
	T_SPHERE,
	T_CYLINDER,
	T_CONE
}				t_rttype;

** rtcamera: object camera
** vector1: origin, necessary
*/
typedef struct	s_rtcamera
{
	t_vec3	origin;
	t_vec3	dir;
	double	f;
	double	width;
	double	height;
}				t_rtcamera;

/*
** rtsphere: object sphere
** vector1: rayon, necessary
** color: color, necessary
** else vectors: complementary translation or/and rotation
*/
typedef struct	s_rtsphere
{
	t_vec3		pos;
	double		rayon;
	int			color;
}				t_rtsphere;

/*
 ** scene: describe object in scene and camera
*/
typedef struct  s_scene
{
    t_rtcamera  camera;
    t_rtsphere  sphere;
}               t_scene;

/*
** rtplan: object plan
** color: color necessary
** vectors: translation or/and rotation complementary

typedef struct	s_rtplan
{
	int			color;
}				t_rtplan;


** rtcylinder: object cylinder, rayon, its origin and its color

typedef struct s_rtcylinder
{
	double		rayon;
	int			origin;
}				t_rtcylinder;


** rtcone: object cone, rayon, its origin and its color

typedef struct s_rtcone
{
	double		rayon;
	int			origin;
}				t_rtcone;


** rtobject: Cross between rttype and structure for its data

typedef struct	s_rtobject
{
	t_rttype	type;
	//inter avec => origin/ Rayon 
	//clr
	void*		objdata;
}				t_rtobject;
*/

/*
** MATH UTILS
*/

void    		rotate_xyz(t_vec3 dest, t_vec3 orig, double yaw, double pitch);
void    		vec3_copy(t_vec3 dest, t_vec3 src);
double			degre2rad(double angle);
double			rad2degre(double angle);

int				load_scene_from_file(const char *path);

t_vec3			**rt_rayprim(t_vec3 p, double kw, double kh);
int				**search_intersect(t_scene s, t_vec3 **map);
void			rt_delvec3(t_vec3 **tab);

#endif
