
#include "mlx/mlx.h"
typedef struct s_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = (unsigned int)color;

	// *(unsigned int*)dst = color;
}
void draw_square(t_data *data, int x, int y, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img,&img.bits_per_pixel,&img.line_length,&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	draw_square(&img, 0, 0,150, 0x00FFF000); // Draw a red square at (100, 100) with size 200

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

}