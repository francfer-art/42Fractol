/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:36:04 by francfer          #+#    #+#             */
/*   Updated: 2024/02/16 18:07:36 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_render_loop(t_fractal fractal)
{
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
}
void leaks()
{
	system("leaks fractol");
}

int	main(int args, char **argv)
{
	t_fractal	fractal_map;
	atexit(leaks);
	if (args == 2 && !ft_strcmp(argv[1], "mandelbrot"))
	{
		fractal_map.fractal_name = argv[1];
		init_render_loop(fractal_map);
	}
	else if ((args == 4) && !ft_strcmp(argv[1], "julia"))
	{
		fractal_map.fractal_name = argv[1];
		fractal_map.julia_x = ft_atoi(argv[2]);
		fractal_map.julia_y = ft_atoi(argv[3]);
		init_render_loop(fractal_map);
	}
	else
	{
		error_message(2);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCES);
}
