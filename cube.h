/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:58:31 by razaha            #+#    #+#             */
/*   Updated: 2020/03/01 18:03:08 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H_
# define CUBE_H_

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define buttonpressmask (1L<<0)
# define keyreleasemask	(1L<<1) 
# define buttonpress 2
# define keyrelease	3

#define true 1
#define false 0

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

#define TEXTURE_HEIGHT 64
#define TEXTURE_WIDTH 64

#define EAGLE "images/redbrick.xpm"

extern const int g_map[MAP_NUM_ROWS][MAP_NUM_COLS];

void    *mlx_ptr;
void    *win_ptr;
void    *twod_img;
void    *threed_img;
void	*textu_img;

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

struct Inter
{
	int		israyfacingdown;
	int		israyfacingup;
	int		israyfacingright;
	int		israyfacingleft;
	float	verthitdistance;
	float 	horzhitdistance;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		foundhorzwallhit;
	float	horzwallhitx;
	float	horzwallhity;
	int		horzwallcontent;
	int		foundvertwallhit;
	float	vertwallhitx;
	float	vertwallhity;
	int		vertwallcontent;
	float	nexthorztouchx;
	float	nexthorztouchy;
	float	nextverttouchx;
	float	nextverttouchy;
	float	xtocheck;
	float	ytocheck;
}	inter;

struct Projec
{
	int		i;
	int		j;
	float	perpdistance;
	float	distanceprojplane;
	float	projectedwallheight;
	int		wallstripheight;
	int		walltoppixel;
	int		wallbottompixel;
	int		texttureoffestx;
	int		texttureoffesty;
	int		distancefromtop;
}	projec;


struct	Textu
{
	void *img;
	int	*data;
	int width;
	int height;
	int bpp;
	int endian;
	int sizeline;
}	textu;

struct line
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
}	line;


void	ft_img_pixel_put_2d(int x, int y, int color);
void    ft_img_pixel_put_3d(int x, int y, int colot);
void    ft_draw_square(float x, float y, float w, float h);
void    ft_draw_line(int x1, int y1, int x2, int y2);
float   normalizeangle(float Angle);
int     maphaswallat(float x, float y);
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
void	ft_projection(void);
void	horinter(float rayangle);
void	verinter(float rayangle);

#endif
