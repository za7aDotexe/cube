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
#define INT_MAX 2147483647

#define TILE_SIZE 32
#define MINIMAP_SCALE_FACTOR 0.25
#define MAP_NUM_ROWS 24
#define MAP_NUM_COLS 24

#define WINDOW_WIDTH (TILE_SIZE * MAP_NUM_COLS)
#define WINDOW_HEIGHT (TILE_SIZE * MAP_NUM_ROWS)

#define FOV_ANGLE (60 * (PI / 180)) 
#define NUM_RAYS (WINDOW_WIDTH * 1)

#define globspeed 0.03

void	ft_img_pixel_put_2d(void *img_ptr, int x, int y, int color);
void    ft_img_pixel_put_3d(void *img_ptr, int x, int y, int colot);
void    ft_draw_square(float x, float y, float w, float h, void *img_ptr);
void    ft_draw_line(int x1, int y1, int x2, int y2, void *img_ptr);
float   normalizeAngle(float Angle);
int     mapHasWallAt(float x, float y);
float   ft_distbpoints(float x1, float y1, float x2, float y2);


void    ft_setup(void);
void    ft_render(void);
int     ft_update(void);

int     ft_presskey(int key);
int     ft_releasekey(int key);

void    ft_rendermap(void);
void    ft_renderplayer(void);

void    ft_moveplayer(void);

void    ft_castallrays(void);
void    ft_renderrays(void);

void ft_3Dprojection(void);

void    *mlx_ptr;
void    *win_ptr;
void    *twod_img;
void    *threed_img;

struct Player
{
    float x;
    float y;
    float width;
    float height;
    int   turndirection;
    int   walkupdown;
    int   walkleftright;
    float rotationangle;
    float walkspeed;
    float turnspeed;
}   player;

struct Ray
{
    float rayangle;
    float wallhitx;
    float wallhity;
    float distance;
    int washitvertical;
    int israyfacingup;
    int israyfacingdown;
    int israyfacingleft;
    int israyfacingright;
    int wallhitcontent;
} rays[NUM_RAYS];

#endif
