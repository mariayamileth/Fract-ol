/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:47:50 by maricont          #+#    #+#             */
/*   Updated: 2023/11/13 18:35:48 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img	new_img(int w, int h, t_win win, char *str)
{
	t_img	image;

	image.win = win;
	image.img_ptr = mlx_new_image(win.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	image.zoom = 1;
	image.name = str;
	image.mouse_x = 0;
	image.mouse_y = 0;
	image.julia_x = 0.0;
	image.julia_y = 0.0;
	image.color = 50;
	image.iter = ITER;
	image.color2 = 0x006600;
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

int	exit_win(t_win *win)
{
	if (win)
		mlx_destroy_window (win->mlx_ptr, win->win_ptr);
	exit(EXIT_SUCCESS);
}

int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	img->mouse_x = (400 - (double)mouse_x) / X;
	img->mouse_y = ((double)mouse_y - 400) / Y;
	if (button == SCROLL_UP)
	{
		img->zoom = img->zoom * 0.9;
		img->color = img->color + 10;
		img->color2 = img->color2 * 2 - 30;
		zoom(*img);
	}
	else if (button == SCROLL_DOWN)
	{
		img->zoom = img->zoom / 0.9;
		img->color = img->color - 10;
		img->color2 = img->color * 2 - 15;
		zoom(*img);
	}
	(void)button;
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr,
		img->img_ptr, 0, 0);
	return (0);
}
