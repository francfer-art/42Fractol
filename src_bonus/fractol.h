/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:01:36 by francfer          #+#    #+#             */
/*   Updated: 2024/01/31 12:56:43 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilib/mlx.h"
# include <X11/X.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCES 0
# define WIDTH 700
# define HEIGHT 700
# define BLACK 0x00001F
# define BLUE 0x0000FF
# define BLUEISH 0x0066FF
# define LIGHTBLUE 0x3399FF
# define SKYBLUE 0x33CCFF
# define DEEPSKYBLUE 0x00BFFF
# define TURQUOISE 0x00CED1
# define CYANISH 0x66FFFF
# define CYAN 0x00FFFF
# define AQUA 0x00FFFF
# define WHITE 0xFFFFFF
# define BEIGE 0xE8E4C9
# define RED 0XFD0101
# define YELLOW 0xFDFD01
# define PURPLE 0xB001FD
# define GREEN 0x6AFD01
# define EE 0x65ffec
# define XK_ESCAPE 0x0035
# define XK_LEFT 0x007B
# define XK_UP 0x007E
# define XK_RIGHT 0x007C
# define XK_DOWN 0x007D
# define XK_LEFT1 0x0000
# define XK_UP1 0x000D
# define XK_RIGHT1 0x0002
# define XK_DOWN1 0x0001
# define XK_PLUS 0x0045
# define XK_MINUS 0x004E
# define XK_PLUS1 0x001E
# define XK_MINUS1 0x002C
# define XK_ZOOM_IN 0x0004
# define XK_ZOOM_OUT 0x0005

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_image
{
	void	*image_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_image	img;
	char	*fractal_name;
	double	escape_val;
	int		iterations;
	double	julia_x;
	double	julia_y;
	double	move_x;
	double	move_y;
	double	zoom;
	int		active;
}			t_fractal;

// UTILS
int			ft_strcmp(char *s1, char *s2);
void		error_message(int fd);
double		ft_atoi(char *str);
int			is_digit(char n);
// INITIALIZATION
void		fractal_init(t_fractal *fractal_map);
void		event_init(t_fractal *fractal);
// RENDERING
void		fractal_render(t_fractal *fractal);
void		handle_pixel_burning(t_complex c, int x, int y,
				t_fractal *fractal);
void		handle_pixel_rose(t_complex z, int x, int y, t_fractal *fractal);
void		handle_pixel_newton(t_complex z, int x, int y, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_image *img, int color);
void		toggle(t_complex *z, t_complex *c, t_fractal *fractal);
// MATH UTILS
double		ft_escale(double num, double new_min, double new_max);
double		ft_escale_color(double num, double new_min, double new_max);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	square_complex(t_complex a);

#endif
