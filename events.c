/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeltahi <haeltahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:25:59 by haeltahi          #+#    #+#             */
/*   Updated: 2023/12/20 13:27:02 by haeltahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keysum(int keysum, t_fractal *fractal)

{
	if (keysum == 53)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		exit(0);
	}
	if (keysum == LEFT_ARROW)
		fractal->shift_x -= 0.5;
	if (keysum == RIGHT_ARROW)
		fractal->shift_x += 0.5;
	if (keysum == UP_ARROW)
		fractal->shift_y -= 0.5;
	if (keysum == DOWN_ARROW)
		fractal->shift_y += 0.5;
	if (keysum == PLUS)
		fractal->iterations_definition += 10;
	if (keysum == MINUS)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->zoom *= 0.5;
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.5;
	}
	fractal_render(fractal);
	return (0);
}
