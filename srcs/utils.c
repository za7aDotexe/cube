#include "cube.h"

void ft_draw_square(float x, float y, float w, float h, void *img_ptr)
{
    float i;
    float j;

    i = 0;
    j = 0;
	while (j++ <= h)
	{
        i = 0;	
		while (i++ <= w)
			ft_img_pixel_put_2d(img_ptr, x + i - 1, y + j - 1, 0xFF0000);
	}
}

void ft_draw_line(int x1, int y1, int x2, int y2, void *img_ptr)
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
    ft_img_pixel_put_2d(img_ptr, x1,y1, 0xffff00);
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

float normalizeAngle(float Angle)
{
	Angle = remainder(Angle, TWO_PI);
	if (Angle < 0)
		Angle = TWO_PI + Angle;
	return Angle;
}

float ft_distbpoints(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ft_img_pixel_put_2d(void *img_ptr, int x, int y, int color)
{
	int *add;
	int bpp;
	int sizeline;
	int endian;
	int cord;

	add = (int *)mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endian);

	if (x  < WINDOW_WIDTH * MINIMAP_SCALE_FACTOR  && y < WINDOW_HEIGHT * MINIMAP_SCALE_FACTOR) 
	{
		cord = (y * sizeline / 4 + x);
		add[cord] = color;
	}
}

void	ft_img_pixel_put_3d(void *img_ptr, int x, int y, int color)
{
	int *add;
	int bpp;
	int sizeline;
	int endian;
	int cord;

	add = (int *)mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endian);

	cord = (y * sizeline / 4 + x) ;
	add[cord] = color;
}