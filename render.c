/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeltahi <haeltahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:26:16 by haeltahi          #+#    #+#             */
/*   Updated: 2023/12/26 14:11:35 by haeltahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	mandelandjulia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strcmp(fractal->name, "julia") == 0)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	color = 0;
	i = 0;
	z.x = map(x, -2, +2, WIDTH) * (fractal->zoom) + fractal->shift_x;
	z.y = map(y, +2, -2, HEIGHT) * (fractal->zoom) + fractal->shift_y;
	mandelandjulia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if (((z.x * z.x) + (z.y * z.y) > fractal->escape_value))
		{
			color = map(i, WHITE, BLACK, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
