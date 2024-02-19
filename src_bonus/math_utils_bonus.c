/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:40:58 by francfer          #+#    #+#             */
/*   Updated: 2024/02/19 11:51:49 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	is_digit(char n)
{
	return (n >= '0' && n <= '9');
}

double	ft_escale(double num, double new_min, double new_max)
{
	double	old_max;
	double	old_min;

	old_max = 800;
	old_min = 0;
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min)
		+ new_min);
}

double	ft_escale_color(double num, double new_min, double new_max)
{
	double	old_max;
	double	old_min;

	old_max = 23;
	old_min = 0;
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min)
		+ new_min);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

t_complex	square_complex(t_complex a)
{
	t_complex	res;

	res.x = (a.x * a.x) - (a.y * a.y);
	res.y = 2 * a.x * a.y;
	return (res);
}
