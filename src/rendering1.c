/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1724/01/16 17:06:41 by francfer          #+#    #+#             */
/*   Updated: 2024/01/31 18:41:13 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel_mandelbrot(t_complex c, int x, int y, t_fractal *fractal)
{
	int			i;
	int			color;
	t_complex	z;

	i = 0;
	z.x = (ft_escale(x, -3, 3) * fractal->zoom) + fractal->move_x;
	z.y = (ft_escale(y, 3, -3) * fractal->zoom) + fractal->move_y;
	toggle(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x + z.y * z.y) > fractal->escape_val)
		{
			color = ft_escale_color(i, BLACK, RED);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	handle_pixel_julia(t_complex c, int x, int y, t_fractal *fractal)
{
	int			i;
	int			color;
	t_complex	z;

	i = 0;
	z.x = (ft_escale(x, -3, 3) * fractal->zoom) + fractal->move_x;
	z.y = (ft_escale(y, 3, -3) * fractal->zoom) + fractal->move_y;
	toggle(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x + z.y * z.y) > fractal->escape_val)
		{
			color = ft_escale_color(i, BLACK, RED);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}
