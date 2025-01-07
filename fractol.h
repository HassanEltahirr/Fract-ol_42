#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "./mlx/mlx.h"
#define WIDTH 800
#define HEIGHT 800

#define RED 0xFF0000
#define GREEN 0x00FF00	
#define BLUE 0x0000FF
# define BLACK 0x000000
# define WHITE 0xFFFFFF
#define PSYCHEDELIC_YELLOW 0xFFFF00	
#define PSYCHEDELIC_PINK 0xFF00FF
#define PSYCHEDELIC_GREEN 0x00FF00
#define PSYCHEDELIC_ORANGE 0xFFA500

#define ESC_KEY 53
#define KEY_PRESS 2
#define LEFT_ARROW 123
#define RIGHT_ARROW 124
#define UP_ARROW 126
#define DOWN_ARROW 125
#define PLUS 69
#define MINUS 78
typedef struct s_img{
    void *img_ptr;
    char *pixels_ptr;
    int bpp;
    int endian;
    int line_len;
}   t_img;

typedef struct s_fractal
{
    char *name;
	void *mlx_connection;
	void *mlx_window;
    t_img img;
    double escape_value;
    int iterations_definition;
    double shift_x;
    double shift_y;
    double zoom;
    double julia_x;
    double julia_y;
}   t_fractal;

typedef struct s_complex
{ 
    double x;
    double y;
}   t_complex;
#define ERROR_MESSAGE "Please enter \n\t/fractol mandelbrot\" or \n\t\" ./fractol julia <value_1> <value_2>\n"""

int ft_strcmp(char *s1,char* s2);
void ft_putstr_fd(char *str,int fd);
void fractal_init(t_fractal *fractal);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1,t_complex z2);
void fractal_render(t_fractal *fractal);
void	my_pixel_put(int x, int y, t_img *img, int color);

double	map(double unscaled_num, double new_min, double new_max,
		double old_max);
int keysum(int keysum,t_fractal* fractal);
int mouse_handler(int button,int x,int y,t_fractal *fractal);
double  atoidbl(char *s);
void mandel_and_julia(t_complex x,t_complex y,t_fractal *fractal);
#endif