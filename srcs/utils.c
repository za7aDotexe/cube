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

void ft_draw_line(int x1, int y1, int x2, int y2)
{
	float x,y,dx,dy,stp;
	int i;

	dx = x2-x1;
	dy = y2-y1;
 
	if(fabs(dx)>=fabs(dy))
		stp = fabs(dx);
	else
		stp = fabs(dy);
	dx=dx/stp;
	dy=dy/stp;
 
	x=x1;
	y=y1;
 
	i=1;
	while(i<=stp)
	{
		ft_img_pixel_put(img_ptr, x, y, 0xFFFF00);
		x=x+dx;
		y=y+dy;
		i=i+1;
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