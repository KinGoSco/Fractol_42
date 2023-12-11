/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:23:11 by nkhachab          #+#    #+#             */
/*   Updated: 2023/06/12 18:33:25 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractol *data)
{
	data->itmax = 50;
	data->zoom = 200;
	data->x_1 = -1.5;
	data->y_1 = -1.7;
	data->color = 274;
}

void	calcul_julia(t_fractol *data)
{
	data->zr = data->x / data->zoom + data->x_1;
	data->zi = data->y / data->zoom + data->y_1;
	data->it = 0;
	while (data->zr * data->zr + data->zi * data->zi < 4
		&& data->it < data->itmax)
	{
		data->tmp = data->zr;
		data->zr = data->zr * data->zr - data->zi * data->zi - 0.7;
		data->zi = 2 * data->zi * data->tmp;
		data->it++;
	}
	if (data->it == data->itmax)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*julia(void *tab)
{
	int			tmp;
	t_fractol	*data;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->ymax)
		{
			calcul_julia(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	julia_px(t_fractol *data)
{
	int			i;
	t_fractol	temp_data;

	i = 0;
	while (i < 120)
	{
		ft_memcpy(&temp_data, data, sizeof(t_fractol));
		temp_data.y = 5 * i;
		temp_data.ymax = 5 * (i + 1);
		julia(&temp_data);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
