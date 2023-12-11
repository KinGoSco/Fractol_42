/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:23:20 by nkhachab          #+#    #+#             */
/*   Updated: 2023/06/12 18:36:55 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractol *data)
{
	data->itmax = 50;
	data->zoom = 200;
	data->x_1 = -1.89;
	data->y_1 = -1.50;
	data->color = 265;
}

void	calcul_mandelbrot(t_fractol *data)
{
	data->cr = data->x / data->zoom + data->x_1;
	data->ci = data->y / data->zoom + data->y_1;
	data->zr = 0;
	data->zi = 0;
	data->it = 0;
	while (data->zr * data->zr + data->zi * data->zi < 4
		&& data->it < data->itmax)
	{
		data->tmp = data->zr;
		data->zr = data->zr * data->zr - data->zi * data->zi + data->cr;
		data->zi = 2 * data->zi * data->tmp + data->ci;
		data->it++;
	}
	if (data->it == data->itmax)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*mandelbrot(void *tab)
{
	t_fractol	*data;
	int			tmp;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->ymax)
		{
			calcul_mandelbrot(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	mandelbrot_px(t_fractol *data)
{
	int			i;
	t_fractol	temp_data;

	i = 0;
	while (i < 120)
	{
		ft_memcpy(&temp_data, data, sizeof(t_fractol));
		temp_data.y = 5 * i;
		temp_data.ymax = 5 * (i + 1);
		mandelbrot(&temp_data);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
