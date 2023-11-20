/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricont <maricont@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:42:00 by maricont          #+#    #+#             */
/*   Updated: 2023/11/13 18:34:21 by maricont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define X 800
# define Y 800
# define ITER 100

# define ESC 53   // key escape
# define ENTER 36 // key "enter"
# define FOLLOW 3 // key "f"
# define COLOR 8  // key "c"
# define UP 126   // key "arrow up"
# define DOWN 125 // key "arrow down"
# define RAND_COLOR 15 // key "r"
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 30
# define KEY_MINUS 44
# define CLICK_R 1
# define CLICK_L 2

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
	double	zoom;
	char	*name;
	double	mouse_x;
	double	mouse_y;
	double	julia_x;
	double	julia_y;
	int		color;
	int		color2;
	int		iter;
}			t_img;

typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}		t_square;

t_complex	ft_mandelbrot(int x, int y, t_img img, int i);
t_img		ft_julia(int x, int y, t_img img);
t_img		ft_fractol(char *str, t_img img, int x, int y);
t_win		new_program(int w, int h, char *str);
t_img		new_img(int w, int h, t_win win, char *str);
void		put_pixel_img(t_img img, int x, int y, int color);
int			exit_win(t_win *win);
void		draw_square(t_square square, t_img img);
int			read_keys(int key_pressed, void *param);
int			read_mouse(int button, int mouse_x, int mouse_y, void *param);
int			continuous_read_keys(int key_pressed, void *param);
int			follow_mouse(int mouse_x, int mouse_y, void *param);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_error(void);
char		*ft_tolower(char *str);
void		zoom(t_img img);
void		ft_putchar(char	*str);
int			ft_validate(char *str);

#endif
