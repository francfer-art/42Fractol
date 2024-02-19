/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:28:29 by francfer          #+#    #+#             */
/*   Updated: 2024/02/19 11:51:45 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	error_message_bonus(int fd)
{
	write(fd, "Allowed Commands:\n", 18);
	write(fd, "./fractol newton\n", 17);
	write(fd, "./fractol rose\n", 15);
	write(fd, "./fractol burning\n", 18);
}

static void	init_render_loop(t_fractal fractal)
{
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
}

int	main(int args, char **argv)
{
	t_fractal	fractal_map;

	if ((args == 2) && !ft_strcmp(argv[1], "burning"))
	{
		fractal_map.fractal_name = argv[1];
		init_render_loop(fractal_map);
	}
	else if ((args == 2) && !ft_strcmp(argv[1], "rose"))
	{
		fractal_map.fractal_name = argv[1];
		init_render_loop(fractal_map);
	}
	else if ((args == 2) && !ft_strcmp(argv[1], "newton"))
	{
		fractal_map.fractal_name = argv[1];
		init_render_loop(fractal_map);
	}
	else
	{
		error_message_bonus(2);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCES);
}

//static void ft_leaks()
//{
//	system("leaks -q fractol_bonus");
// atexit(ft_leaks);
//}