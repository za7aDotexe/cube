#ifndef CUBE_H_  
#define CUBE_H_

#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define ButtonPressMask (1L<<0)
#define KeyReleaseMask	(1L<<1) 
#define ButtonPress	2
#define KeyRelease	3

#define TRUE 1
#define FALSE 0

#define PI 3.14159265
#define TWO_PI 6.28318530 

#define TILE_SIZE 32
#define MINIMAP_SCALE_FACTOR 1
#define MAP_NUM_ROWS 24
#define MAP_NUM_COLS 24

#define WINDOW_WIDTH (TILE_SIZE * MAP_NUM_COLS)
#define WINDOW_HEIGHT (TILE_SIZE * MAP_NUM_ROWS)

#define FOV_ANGLE (60 * (PI / 180)) 
#define NUM_RAYS WINDOW_WIDTH

#define globspeed 0.05

void	ft_img_pixel_put(void *img_ptr, int x, int y, int color);
void    ft_draw_square(float x, float y, float w, float h);
void    ft_draw_line(int x1, int y1, int x2, int y2);

void    ft_setup();
void    ft_render();
int     ft_update();

int     ft_presskey(int key);
int     ft_releasekey(int key);

void    ft_renderMap();
void    ft_renderPlayer();

void    ft_movePlayer();
void    ft_castRays();
int     mapHasWallAt(float x, float y);

void    *mlx_ptr;
void    *win_ptr;
void    *img_ptr;

struct Player
{
    float x;
    float y;
    float width;
    float height;
    int   turnDirection;
    int   walkUPDOWN;
    int   walkLEFTRIGHT;
    float rotationAngle;
    float walkSpeed;
    float turnSpeed;
}   player;

#endif