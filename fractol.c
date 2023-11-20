/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:41:43 by maricont          #+#    #+#             */
/*   Updated: 2023/11/13 18:23:38 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	read_keys(int key_pressed, void *param)
{
	t_img	*img;
	int		iter;

	img = (t_img *)param;
	iter = ITER;
	if (key_pressed == ESC || !img)
		exit_win(&img->win);
	else if (key_pressed == COLOR)
	{
		img->color2 = img->color2 * 2 - 15;
		zoom(*img);
	}
	else
		return (-1);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr,
		img->img_ptr, 0, 0);
	return (0);
}

t_img	ft_type_julia(char	*str, t_img img)
{
	if (ft_strcmp(str, "julia1") == 0)
	{
		img.julia_x = 0.;
		img.julia_y = 0.8;
	}
	else if (ft_strcmp(str, "julia2") == 0)
	{
		img.julia_x = 0.37;
		img.julia_y = 0.1;
	}
	else if (ft_strcmp(str, "julia3") == 0)
	{
		img.julia_x = 0.355;
		img.julia_y = 0.355;
	}
	return (img);
}

t_img	ft_fractol(char *str, t_img img, int x, int y)
{
	t_complex	n;

	img.name = str;
	while (y <= Y)
	{
		while (x <= X)
		{
			if (ft_strcmp(str, "mandelbrot") == 0)
				n = ft_mandelbrot(x, y, img, 0);
			else
			{
				img = ft_type_julia(str, img);
				img = ft_julia(x, y, img);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (img);
}

int	ft_validate(char *str)
{
	if (ft_strcmp(ft_tolower(str), "mandelbrot") == 0
		|| ft_strcmp(ft_tolower(str), "julia1") == 0
		|| ft_strcmp(ft_tolower(str), "julia2") == 0
		|| ft_strcmp(ft_tolower(str), "julia3") == 0)
		return (0);
	else
		return (-1);
}

int	main(int argc, char *argv[])
{
	t_win	win;
	t_img	img;

	if (argc > 1)
	{
		if (ft_validate(argv[1]) == 0)
		{
			win = new_program(X, Y, argv[1]);
			if (!win.mlx_ptr || !win.win_ptr)
				return (-1);
			img = new_img(X, Y, win, argv[1]);
			img = ft_fractol(argv[1], img, 0, 0);
			mlx_put_image_to_window (img.win.mlx_ptr, img.win.win_ptr,
				img.img_ptr, 0, 0);
			mlx_key_hook (win.win_ptr, read_keys, &img);
			mlx_hook(win.win_ptr, 17, 0, exit_win, &win);
			mlx_mouse_hook(win.win_ptr, read_mouse, &img);
			mlx_loop(win.mlx_ptr);
		}
		else
			ft_error();
	}
	else
		ft_error();
	return (0);
}
