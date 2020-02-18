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
  int dx; 
  int sx; 
  int dy; 
  int sy;
  int err;
  int e2;
  
  dx = abs(x2-x1);
  sx = x1<x2 ? 1 : -1;
  dy = abs(y2-y1);
  sy = y1<y2 ? 1 : -1; 
  err = (dx>dy ? dx : -dy)/2; 
  e2 = 0;
 
  while(1){
    ft_img_pixel_put(img_ptr, x1,y1, 0xffff00);
    if (x1==x2 && y1==y2) 
		break;
    e2 = err;
    if (e2 >-dx)
	{ 
		err -= dy; 
		x1 += sx; 
	}
    if (e2 < dy)
	{ 
		err += dx; 
		y1 += sy; 
	}
  }
}


void	ft_img_pixel_put(void *img_ptr, int x, int y, int color)
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