/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:20:33 by francfer          #+#    #+#             */
/*   Updated: 2024/02/19 11:51:54 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * img->bpp / 8);
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	toggle(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->fractal_name, "julia"))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = (ft_escale(x, 3, -3)) * fractal->zoom + fractal->move_x;
	z.y = (ft_escale(y, -3, 3)) * fractal->zoom + fractal->move_y;
	toggle(&z, &c, fractal);
	if (!ft_strcmp(fractal->fractal_name, "burning"))
		handle_pixel_burning(c, x, y, fractal);
	else if (!ft_strcmp(fractal->fractal_name, "rose"))
		handle_pixel_rose(z, x, y, fractal);
	else if (!ft_strcmp(fractal->fractal_name, "newton"))
		handle_pixel_newton(z, x, y, fractal);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.image_ptr, 0, 0);
}
