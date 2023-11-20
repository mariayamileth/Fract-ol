/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:33:42 by maricont          #+#    #+#             */
/*   Updated: 2023/11/13 18:34:48 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_mandelbrot(int x, int y, t_img img, int i)
{
	t_complex	pos;
	t_complex	z;
	double		temp;

	pos.y = ((((double)y * -4 * img.zoom) / Y) + 2.0 * img.zoom)
		+ (1 * img.mouse_y);
	pos.x = ((((double)x * 4 * img.zoom) / X) - 2.0 * img.zoom)
		+ (1 * img.mouse_x);
	z.x = pos.x;
	z.y = pos.y;
	while (i < ITER)
	{
		temp = pos.x * pos.x - (pos.y * pos.y) + z.x;
		pos.y = 2 * pos.x * pos.y + z.y;
		pos.x = temp;
		if ((pos.x * pos.x + pos.y * pos.y) > 4)
		{
			put_pixel_img(img, x, y, i * img.color + img.color2);
			return (z);
		}
		i++;
	}
	put_pixel_img(img, x, y, 0);
	return (z);
}

t_img	ft_julia(int x, int y, t_img img)
{
	t_complex	pos;
	int			i;
	double		temp;

	i = 0;
	pos.y = ((((double)y * -4 * img.zoom) / Y) + 2 * img.zoom)
		+ (1 * img.mouse_y);
	pos.x = ((((double)x * 4 * img.zoom) / X) - 2 * img.zoom)
		+ (1 * img.mouse_x);
	while (i < img.iter)
	{
		temp = pos.x * pos.x - (pos.y * pos.y) + img.julia_x;
		pos.y = 2 * pos.x * pos.y + img.julia_y;
		pos.x = temp;
		if ((pos.x * pos.x + pos.y * pos.y) > 4)
		{
			put_pixel_img(img, x, y, i * img.color + img.color2);
			return (img);
		}
		i++;
	}
	put_pixel_img(img, x, y, 0);
	return (img);
}
