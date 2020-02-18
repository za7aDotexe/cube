#include "cube.h"

void ft_draw_square(float x, float y, float w, float h)
{
    float i;
    float j;

    i = 0;
    j = 0;
	while (j++ <= h)
	{
        i = 0;	
		while (i++ <= w)
			ft_img_pixel_put(img_ptr, x + i - 1, y + j - 1, 0xFF0000);
	}
}

void	ft_img_pixel_put(void *img_ptr, float x, float y, int color)
{
	int *add;
	int bpp;
	int sizeline;
	int endian;
	int cord;

	add = (int *)mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endian);

	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		cord = (y * WINDOW_WIDTH + x) ;
		add[cord] = color;
	}
}