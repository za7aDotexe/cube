/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:58:31 by razaha            #+#    #+#             */
/*   Updated: 2020/11/03 20:53:40 by razaha           ###   ########.fr       */
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
# include "gnl/get_next_line.h"

# define buttonpressmask (1L<<0)
# define keyreleasemask	(1L<<1)
# define destroynotifymask (0L)
# define buttonpress 2
# define keyrelease	3
# define destroynotify 17

#define true 1
#define false 0

#define PI 3.14159265
#define TWO_PI 6.28318530
#define INT_MAX 2147483647


//tileheight = scren h / map h
//tilewidth = screen w / map w
#define TILE_SIZE 32
#define MINIMAP_SCALE_FACTOR 0.25
#define MAP_NUM_ROWS 24
#define MAP_NUM_COLS 24

// extern int MAP_NUM_ROWS;
// extern int MAP_NUM_COLS;

// #define WINDOW_WIDTH (TILE_SIZE * MAP_NUM_COLS)
// #define WINDOW_HEIGHT (TILE_SIZE * MAP_NUM_ROWS)

int WINDOW_WIDTH;
int WINDOW_HEIGHT;
int cols;
int rows;

#define FOV_ANGLE (60 * (PI / 180)) 
#define NUM_RAYS (768 * 1)

#define globspeed 0.01

#define TEXTURE_HEIGHT 64
#define TEXTURE_WIDTH 64

char *NOTXT;
char *SOTXT;
char *WETXT;
char *EATXT;
char *SPRIT;
int FCOL;
int CCOL;

extern const char g_map[24][24];

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
	float spritehitx;
	float spritehity;
	float walldistance;
	float spritedistance;
	int washitvertical;
	int israyfacingup;
	int israyfacingdown;
	int israyfacingleft;
	int israyfacingright;
	int wallhitcontent;
	int foundhorspritehit;
	int foundverspritehit;
	int wassphitvertical;
} rays[NUM_RAYS];

struct Inter
{
	int		israyfacingdown;
	int		israyfacingup;
	int		israyfacingright;
	int		israyfacingleft;
	float	verthitdistance;
	float 	horzhitdistance;
	float	vertsphitdistance;
	float 	horzsphitdistance;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		foundhorzwallhit;
	int		foundhorspritehit;
	float	horzwallhitx;
	float	horzwallhity;
	float	horzspritehitx;
	float	horzspritehity;
	int		horzwallcontent;
	int		foundvertwallhit;
	int		foundverspritehit;
	float	vertwallhitx;
	float	vertwallhity;
	float	verspritehitx;
	float	verspritehity;
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

typedef struct	Textu
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

typedef struct		s_vector
{
	float x;
	float y;
}					t_vector;

typedef struct		s_sprite
{
	int x;
	int y;
	int	px;
	int	py;
	int scale;
	struct s_sprite *next;
}					t_sprite;

t_sprite *g_sprites;
textu g_textures[5];

void	ft_img_pixel_put_2d(int x, int y, int color);
void    ft_img_pixel_put_3d(int x, int y, int color);
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
int		ft_destroywindown(void);
void    ft_rendermap(void);
void    ft_renderplayer(void);
void    ft_moveplayer(void);
void    ft_castallrays(void);
void    ft_renderrays(void);
void	ft_projection(void);
void	horinter(float rayangle, int stripid);
void	verinter(float rayangle, int stripid);
int		mapinter(float x, float y);
float	ft_get_angleabc(t_vector a, t_vector b, t_vector c);
int		ft_get_pixel(int x, int y);
void	ft_draw_sprite(int x, int y, int scale);
void    ft_fill_sprite(int stripid, int sx, int sy);
void    ft_draw_sprites(void);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	ft_read_cub_file(int filedesc);
int		rgb_to_hex(int r, int g, int b);
#endif
