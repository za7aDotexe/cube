/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:58:31 by razaha            #+#    #+#             */
/*   Updated: 2020/11/18 19:33:40 by razaha           ###   ########.fr       */
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
# include <errno.h>
# include "parse/parser.h"

# define buttonpressmask (1L<<0)
# define keyreleasemask	(1L<<1)
# define destroypressmask (0L)
# define buttonpress 2
# define keyrelease	3
# define destroypress 17
#define true 1
#define false 0
#define PI 3.14159265
#define TWO_PI 6.28318530
#define INT_MAX 2147483647
#define TILE_SIZE 32
#define MMAP_SCE_FACTOR 0.1
#define FOV_ANGLE (60 * (PI / 180)) 
#define NUM_RAYS (WINDOW_WIDTH * 1)
#define TEXTURE_HEIGHT 64
#define TEXTURE_WIDTH 64


#define globspeed 0.03
char	*NOTXT;
char	*SOTXT;
char	*WETXT;
char	*EATXT;
char	*SPRIT;
int		FCOL;
int		CCOL;
int		WINDOW_WIDTH;
int		WINDOW_HEIGHT;
int		cols;
int		rows;

void    *mlx_ptr;
void    *win_ptr;
void    *twod_img;
void    *threed_img;
void	*textu_img;

struct Player
{
	int player;
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
	int washitvertical;
	int israyfacingup;
	int israyfacingdown;
	int israyfacingleft;
	int israyfacingright;
	int wallhitcontent;
	int wassphitvertical;
};

typedef	struct tmp_sprite
{
	int			hit_horz;
	int			hit_vert;
	double		hit_x;
	double		hit_y;
	double		distance;
	int			index_x;
	int			index_y;

} TMP_SPRITE;

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
	int		i_sp;
	TMP_SPRITE	*tmp_sprite;
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
}	g_line;

typedef struct		s_vector
{
	float x;
	float y;
}					t_vector;

typedef struct		s_sprite
{
	double	x;
	double	y;
	int		index_x;
	int		index_y;
	double	distance;
	int		num_ray;
	double	angle;
	struct s_sprite *next;
}					t_sprite;

struct Ray *rays;
t_vector	ab;
t_vector	cb;
t_sprite *g_sprites;
textu g_textures[5];

void	ft_img_pixel_put_2d(int x, int y, int color);
void    ft_img_pixel_put_3d(int x, int y, int color);
void	ft_draw_square(float x, float y, float w, float h);
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
void    ft_fill_sprite();
void    ft_draw_sprites(void);
void	ft_lstclear(void);
void	ft_swap_list(t_sprite **current ,t_sprite **index);
int		ft_sprite_exist(int index_x, int index_y);
void	ft_sprite_add_sorted(t_sprite *new);
void	ft_new_sprite(TMP_SPRITE tmp_sprite, int num_ray, float angle);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	ft_read_cub_file(int filedesc);
int		rgb_to_hex(int r, int g, int b);
int		get_next_line(int fd, char **line);
#endif
