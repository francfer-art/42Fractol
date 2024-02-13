/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1724/01/16 17:06:41 by francfer          #+#    #+#             */
/*   Updated: 2024/01/31 12:45:17 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel_burning(t_complex c, int x, int y, t_fractal *fractal)
{
	t_complex	temp;
	int			iter;
	int			color;
	t_complex	z;

	iter = 0;
	z.x = (ft_escale(x, 3, -3)) * fractal->zoom + fractal->move_x;
	z.y = (ft_escale(y, -3, 3)) * fractal->zoom + fractal->move_y;
	toggle(&z, &c, fractal);
	while (iter < fractal->iterations)
	{
		temp.x = z.x * z.x - z.y * z.y + c.x;
		temp.y = 2.0 * fabs(z.x * z.y) + c.y;
		z = temp;
		if ((z.x * z.x + z.y * z.y) > 4)
		{
			color = ft_escale_color(iter, BLACK, RED);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		iter++;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	handle_pixel_rose(t_complex z, int x, int y, t_fractal *fractal)
{
	t_complex	temp;
	int			iter;
	int			color;

	iter = 0;
	while (iter < fractal->iterations)
	{
		temp.x = cos(z.x) * cosh(z.y);
		temp.y = -sin(z.x) * sinh(z.y);
		z = temp;
		if ((z.x * z.x + z.y * z.y) > 100)
		{
			color = ft_escale_color(iter, BLACK, RED);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		iter++;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	handle_pixel_newton(t_complex z, int x, int y, t_fractal *fractal)
{
	int			iter;
	double		r;
	double		theta;
	t_complex	delta;
	int			color;

	iter = 0;
	while (iter < fractal->iterations)
	{
		r = sqrt(z.x * z.x + z.y * z.y);
		theta = atan2(z.y, z.x);
		delta.x = (pow(r, 3) * cos(3 * theta) - 1) / (3 * pow(r, 2));
		delta.y = (pow(r, 3) * sin(3 * theta)) / (3 * pow(r, 2));
		z.x -= delta.x;
		z.y -= delta.y;
		if (sqrt(delta.x * delta.x + delta.y * delta.y) < 0.001)
		{
			color = ft_escale_color(iter, BLACK, RED);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		iter++;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}
