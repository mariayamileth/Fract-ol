/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:17:21 by maricont          #+#    #+#             */
/*   Updated: 2023/11/13 18:23:47 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_error(void)
{
	char	*str;

	str = "Debe colocar uno de los siguientes argumentos:\n";
	ft_putchar(str);
	str = "Mandelbrot\nJulia1\nJulia2\nJulia3\nJulia4\n";
	ft_putchar(str);
	return (0);
}

char	*ft_tolower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

void	zoom(t_img img)
{
	t_complex	n;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y <= Y)
	{
		while (x <= X)
		{
			if (ft_strcmp(img.name, "mandelbrot") == 0)
				n = ft_mandelbrot(x, y, img, 0);
			else
				ft_julia (x, y, img);
			x++;
		}
		x = 0;
		y++;
	}
}
