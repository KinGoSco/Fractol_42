/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:24:23 by nkhachab          #+#    #+#             */
/*   Updated: 2023/06/12 17:56:17 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 600

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_ptr;
	int		edn;
	int		spl;
	int		np;
	int		fract;
	int		color;
	int		x;
	int		y;
	int		ymax;
	int		it;
	int		itmax;
	double	zoom;
	double	x_1;
	double	y_1;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	tmp;
}			t_fractol;

int			key_hook(int keycode, t_fractol *data);
void		ft_zoom(int x, int y, t_fractol *data);
void		ft_dezoom(int x, int y, t_fractol *data);
int			mouse_hook(int mousecode, int x, int y, t_fractol *data);

void		init_mandelbrot(t_fractol *data);
void		calcul_mandelbrot(t_fractol *data);
void		*mandelbrot(void *tab);
void		mandelbrot_px(t_fractol *data);

void		init_julia(t_fractol *data);
void		calcul_julia(t_fractol *data);
void		*julia(void *tab);
void		julia_px(t_fractol *data);

int			ft_close(void);
void		put_pxl_to_img(t_fractol *data, int x, int y, int color);

void		calcul_fract(t_fractol *data);
void		init_fract(t_fractol *data);
void		mlx_win_init(t_fractol *data);
int			comp_fract(char **av, t_fractol *data);

void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_putendl_fd(char *s, int fd);
int			ft_strcmp(char *s1, char *s2);

#endif
