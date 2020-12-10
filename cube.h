/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:58:31 by razaha            #+#    #+#             */
/*   Updated: 2020/12/10 18:32:40 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "mlx.h"
# include "parse/parser.h"
# include <math.h>
# include <errno.h>

# define BUTTONPRESSMASK (1L<<0)
# define KEYRELEASEMASK	(1L<<1)
# define DESTROYPRESSMASK (0L)
# define BUTTONPRESS 2
# define KEYRELEASE	3
# define DESTROYPRESS 17
# define TRUE 1
# define FALSE 0
# define PI 3.14159265
# define TWO_PI 6.28318530
# define INT_MAX 2147483647
# define TILE_SIZE 32
# define FOV_ANGLE (60 * (PI / 180))
# define NUM_RAYS (g_window_width * 1)
# define GLOBSPEED 0.04

int					g_save;
void				*g_mlx_ptr;
void				*g_win_ptr;
void				*g_threed_img;

struct				s_player
{
	int				player;
	float			x;
	float			y;
	int				turndirection;
	int				walkupdown;
	int				walkleftright;
	float			rotationangle;
	float			walkspeed;
	float			turnspeed;
}					g_player;

struct				s_ray
{
	float			rayangle;
	float			wallhitx;
	float			wallhity;
	float			spritehitx;
	float			spritehity;
	float			walldistance;
	int				washitverical;
	int				israyfacingup;
	int				israyfacingdown;
	int				israyfacingleft;
	int				israyfacingright;
	int				wallhitcontent;
	int				wassphitverical;
};

typedef	struct		s_tmp_sprite
{
	int				hit_hor;
	int				hit_ver;
	double			hit_x;
	double			hit_y;
	double			distance;
	int				index_x;
	int				index_y;

}					t_tmp_sprite;

struct				s_inter
{
	int				israyfacingdown;
	int				israyfacingup;
	int				israyfacingright;
	int				israyfacingleft;
	float			verhitdistance;
	float			horhitdistance;
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	int				fndhorwallhit;
	float			horwallhitx;
	float			horwallhity;
	int				horwallcontent;
	int				fndverwallhit;
	float			verwallhitx;
	float			verwallhity;
	int				verwallcontent;
	float			nexthortouchx;
	float			nexthortouchy;
	float			nextvertouchx;
	float			nextvertouchy;
	float			xtocheck;
	float			ytocheck;
	int				spr;
	t_tmp_sprite	*tmp_sprite;
}					g_inter;

struct				s_projec
{
	int				i;
	int				j;
	float			perpdistance;
	float			distanceprojplane;
	float			projectedwallheight;
	int				wallstripheight;
	int				walltoppixel;
	int				wallbottompixel;
	int				texttureoffestx;
	int				texttureoffesty;
	int				distancefromtop;
}					g_projec;

typedef	struct		s_textu
{
	void			*img;
	int				*data;
	int				width;
	int				height;
	int				bpp;
	int				endian;
	int				sizeline;
}					t_textu;

struct				s_line
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					g_line;

typedef struct		s_vector
{
	float			x;
	float			y;
}					t_vector;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				index_x;
	int				index_y;
	double			distance;
	int				num_ray;
	double			angle;
	struct s_sprite *next;
}					t_sprite;

struct s_ray		*g_rays;
t_vector			g_ab;
t_vector			g_cb;
t_sprite			*g_sprites;
t_textu				g_textures[5];

void				ft_initialize(void);
void				ft_img_pixel_put_3d(int x, int y, int color);
float				normalizeangle(float angle);
int					maphaswallat(float x, float y);
float				ft_dstbpoints(float x1, float y1, float x2, float y2);
void				ft_render(void);
int					ft_update(void);
int					ft_presskey(int key);
int					ft_releasekey(int key);
int					ft_destroywindown(void);
void				ft_moveplayer(void);
void				ft_castallrays(void);
void				ft_projection(void);
void				horinter(float rayangle);
void				verinter(float rayangle);
int					mapinter(float x, float y);
float				ft_get_angleabc(t_vector a, t_vector b, t_vector c);
int					ft_get_pixel(int x, int y);
void				ft_fill_sprite(t_tmp_sprite tmp_sprite);
void				ft_draw_sprites(void);
void				ft_sprite_clear(void);
void				ft_swap_list(t_sprite **current, t_sprite **index);
int					ft_sprite_exist(int index_x, int index_y);
void				ft_sprite_add_sorted(t_sprite *new);
void				ft_new_sprite(t_tmp_sprite tmp_sprite,
int num_ray, float angle);
int					ft_check_extension(char *s, char *ext);
void				ft_read_cub_file(int filedesc);
int					rgb_to_hex(int r, int g, int b);
int					get_next_line(int fd, char **line);
int					ft_is_save(char *save);
void				ft_screenshot(uint16_t bitcount, int width_in_bytes);
#endif
