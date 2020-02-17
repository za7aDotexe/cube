#ifndef CUBE_H_  
#define CUBE_H_

#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define ButtonPressMask (1L<<0)
#define ButtonPress	2

#define TRUE 1
#define FALSE 0

#define screenWidth 800
#define screenHeight 800

int     ft_render();
int     ft_processinput(int key);

void    ft_draw_square(float x, float y, float w, float h);
void	ft_img_pixel_put(void *img_ptr, float x, float y, int color);

void    *mlx_ptr;
void    *win_ptr;
void    *img_ptr;

int x,y;




#endif