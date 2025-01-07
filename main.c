/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeltahi <haeltahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:26:10 by haeltahi          #+#    #+#             */
/*   Updated: 2023/12/26 14:12:45 by haeltahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_input1(char *str1, char *str2)
{
	if (('+' == *str2 || '-' == *str2) || ('+' == *str1 || '-' == *str1))
	{
		str1++;
		str2++;
	}
	if (('+' == *str2 || '-' == *str2) || ('+' == *str1 || '-' == *str1))
	{
		ft_putstr_fd("error", 2);
		return (0);
	}
	if ((atoidbl(str1) >= -2 && atoidbl(str1) <= 2) && (atoi(str2) >= -2
			&& atoidbl(str2) <= 2))
		return (1);
	return (0);
}

int	check_input(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (1);
	while (*str1)
	{
		if (!(is_digit(*str1) || *str1 == '.' || *str1 == '-' || *str1 == '+'))
			return (1);
		if (*str1 == '.' && (*(str1 + 1) == '\0' || !is_digit(*(str1 + 1))))
			return (1);
		str1++;
	}
	while (*str2)
	{
		if (!((*str2 >= '0' && *str2 <= '9') || *str2 == '.' || *str2 == '-'
				|| *str2 == '+'))
			return (1);
		if (*str2 == '.' && (*(str2 + 1) == '\0' || !is_digit(*(str2 + 1))))
			return (1);
		str2++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0) || (ac == 4
			&& ((ft_strcmp(av[1], "julia") == 0) && !(check_input(av[2], av[3]))
				&& (check_input1(av[2], av[3])))))
	{
		fractal.name = av[1];
		if ((ac == 4 && ft_strcmp(av[1], "julia") == 0))
		{
			fractal.name = av[1];
			fractal.julia_x = atoidbl(av[2]);
			fractal.julia_y = atoidbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_hook(fractal.mlx_window, 2, 0, keysum, &fractal);
		mlx_hook(fractal.mlx_window, 4, 1L << 2, mouse_handler, &fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
