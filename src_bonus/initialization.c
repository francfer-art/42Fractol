/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:50:27 by francfer          #+#    #+#             */
/*   Updated: 2024/01/29 11:44:25 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <limits.h>

static void	error_malloc(void)
{
	perror("PROBLEM ALLOCATING MEMORY!");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_val = 4;
	fractal->iterations = 10;
	fractal->move_x = 0.0;
	fractal->move_y = 0.0;
	fractal->zoom = 1;
	fractal->active = 1;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		error_malloc();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->fractal_name);
	if (!fractal->mlx_window)
	{
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->img.image_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (!fractal->img.image_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		error_malloc();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.image_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	event_init(fractal);
	data_init(fractal);
}
