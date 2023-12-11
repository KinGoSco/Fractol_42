/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:23:32 by nkhachab          #+#    #+#             */
/*   Updated: 2023/06/12 17:56:00 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcul_fract(t_fractol *data)
{
	if (data->itmax < 0)
		data->itmax = 0;
	if (data->fract == 0)
		mandelbrot_px(data);
	else if (data->fract == 1)
		julia_px(data);
}

void	init_fract(t_fractol *data)
{
	if (data->fract == 0)
		init_mandelbrot(data);
	else if (data->fract == 1)
		init_julia(data);
	calcul_fract(data);
}

void	mlx_win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->np, &data->spl, &data->edn);
}

int	comp_fract(char **av, t_fractol *data)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		data->fract = 1;
	else
	{
		ft_putendl_fd("Use ./fractol \"mandelbrot\", \"julia\"", 1);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	*data;

	data = (t_fractol *) malloc(sizeof(t_fractol));
	if (!data)
		return (-1);
	if (ac == 2)
	{
		if ((comp_fract(av, data)) == 0)
			return (0);
		mlx_win_init(data);
		init_fract(data);
		mlx_hook(data->win, 17, 0L, ft_close, data);
		mlx_key_hook(data->win, key_hook, data);
		mlx_mouse_hook(data->win, mouse_hook, data);
		mlx_loop(data->mlx);
	}
	else
		ft_putendl_fd("Use ./fractol \"mandelbrot\", \"julia\"", 1);
	return (0);
}
