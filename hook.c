/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:22:59 by nkhachab          #+#    #+#             */
/*   Updated: 2023/06/08 17:17:21 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractol *data)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		data->x_1 -= 30 / data->zoom;
	else if (keycode == 124)
		data->x_1 += 30 / data->zoom;
	else if (keycode == 125)
		data->y_1 += 30 / data->zoom;
	else if (keycode == 126)
		data->y_1 -= 30 / data->zoom;
	else if (keycode == 49)
		init_fract(data);
	else if (keycode == 18)
		data->color = 1677300;
	calcul_fract(data);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x_1 = (x / data->zoom + data->x_1) - (x / (data->zoom * 1.3));
	data->y_1 = (y / data->zoom + data->y_1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->itmax++;
}

void	ft_dezoom(int x, int y, t_fractol *data)
{
	data->x_1 = (x / data->zoom + data->x_1) - (x / (data->zoom / 1.3));
	data->y_1 = (y / data->zoom + data->y_1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->itmax--;
}

int	mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, data);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, data);
	calcul_fract(data);
	return (0);
}
