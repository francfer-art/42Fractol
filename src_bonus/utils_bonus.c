/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:01:23 by francfer          #+#    #+#             */
/*   Updated: 2024/02/19 11:52:02 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	error_message(int fd)
{
	write(fd, "Allowed Commands:\n", 18);
	write(fd, "./fractol mandelbrot\n", 21);
	write(fd, "./fractol julia <real value> <imaginary value>\n", 47);
}

double	ft_atoi(char *str)
{
	double	result;
	double	decimalmult;
	int		sign;

	result = 0.0;
	decimalmult = 0.1;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str == '-')
			sign *= -1;
	str++;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0') + 0.0;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			result += (*str++ - '0') * decimalmult;
			decimalmult *= 0.1;
		}
	}
	return (result * sign);
}
