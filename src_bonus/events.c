/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:14:05 by francfer          #+#    #+#             */
/*   Updated: 2024/01/29 12:31:15 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strcmp(fractal->fractal_name, "julia") && fractal->active == -1)
	{
		fractal->julia_x = (ft_escale(x, -3, +3) * fractal->zoom)
			+ fractal->move_x;
		fractal->julia_y = (ft_escale(y, +3, -3) * fractal->zoom)
			+ fractal->move_y;
		fractal_render(fractal);
	}
	return (0);
}

static int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.image_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(EXIT_SUCCES);
}

static int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_ESCAPE)
		close_handler(fractal);
	else if (keysym == XK_LEFT || keysym == XK_LEFT1)
		fractal->move_x += 0.5 * fractal->zoom;
	else if (keysym == XK_RIGHT || keysym == XK_RIGHT1)
		fractal->move_x -= 0.5 * fractal->zoom;
	else if (keysym == XK_UP || keysym == XK_UP1)
		fractal->move_y -= 0.5 * fractal->zoom;
	else if (keysym == XK_DOWN || keysym == XK_DOWN1)
		fractal->move_y += 0.5 * fractal->zoom;
	else if (keysym == XK_PLUS || keysym == XK_PLUS1)
		fractal->iterations += 10;
	else if (keysym == XK_MINUS || keysym == XK_MINUS1)
		fractal->iterations -= 10;
	else if (keysym == 14)
		fractal->active *= -1;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;
	double	dx;
	double	dy;

	zoom_factor = 0.03;
	if (button == XK_ZOOM_OUT)
		fractal->zoom /= (1.0 + zoom_factor);
	else if (button == XK_ZOOM_IN)
		fractal->zoom *= (1.0 + zoom_factor);
	else
		return (0);
	mouse_x = ft_escale(x, 3, -3) * fractal->zoom;
	mouse_y = ft_escale(y, -3, 3) * fractal->zoom;
	dx = mouse_x - fractal->move_x * fractal->zoom;
	dy = mouse_y - fractal->move_y * fractal->zoom;
	fractal->move_x += dx * zoom_factor;
	fractal->move_y += dy * zoom_factor;
	fractal_render(fractal);
	return (0);
}

void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask, julia_track,
		fractal);
}
