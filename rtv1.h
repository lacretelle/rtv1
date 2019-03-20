/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:04:01 by madufour          #+#    #+#             */
/*   Updated: 2019/03/18 15:16:42 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include <mlx.h>
# include <pthread.h>

# define FRACT_W 800
# define FRACT_H 800

typedef struct	s_compl
{
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
}				t_compl;

typedef struct	s_conf
{
	double		zoomx;
	double		zoomy;
}				t_conf;

typedef struct	s_drag
{
	int			x;
	int			y;
	char		on;
}				t_drag;

typedef struct	s_fract
{
	t_drag		d;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom;
	double		offx;
	double		offy;
	int			it_max;
	double		j_cr;
	double		j_ci;
	char		name;
	char		palette;
	char		m_move;
	char		drag;
}				t_fract;

typedef struct	s_mlx
{
	t_fract		f;
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			size_line;
	int			endian;
	int			*data;
	int			size_x;
	int			size_y;
	char		use;
}				t_mlx;

typedef struct	s_data
{
	t_mlx		*mlx;
	t_conf		c;
	int			y;
}				t_data;

typedef struct	s_mult
{
	pthread_t	thread[900];
	t_data		data[900];
}				t_mult;

t_mlx			fl_user(t_mlx mlx);
t_mlx			fl_mandelbrot(t_mlx *mlx);
t_mlx			fl_julia(t_mlx *mlx);
t_mlx			fl_burningship(t_mlx *mlx);
t_fract			fl_init(char c);
void			fl_draw(t_mlx *mlx, int x, int y, int i);
void			fl_clear_img(t_mlx *mlx);
int				fl_color(int i, t_mlx mlx);
int				fl_color_psy(int i, t_mlx mlx);
int				fl_key(int key, void *param);
int				fl_close(void *param);
int				fl_mouse(int k, int x, int y, void *param);
int				fl_mouse_move(int x, int y, void *param);
int				fl_mouse_release(int k, int x, int y, void *param);
#endif
