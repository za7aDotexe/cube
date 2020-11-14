/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:52:42 by razaha            #+#    #+#             */
/*   Updated: 2020/11/14 19:53:56 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cube.h"

void		ft_draw_sprite(int x, int y, int scale, int distance)
{
	float i;
	float j;

	i = 0;
	while (i++ <= scale)
	{
		if ((x + i) < NUM_RAYS && (x + i) > 0
		&& rays[x + (int)i].walldistance > distance)
		{
			j = 0;
			while (j++ <= scale)
			{
				if ((x + (int)i - 1) > 0 && (x + (int)i - 1) < WINDOW_WIDTH &&
					(y + (int)j - 1) > 0 && (y + (int)j - 1) < WINDOW_HEIGHT)
				{
					int color = ft_get_pixel(g_textures[4].width * (i / scale),
					g_textures[4].height * (j / scale));
					if (color && color != -1)
						ft_img_pixel_put_3d(x + i - 1, y + j - 1, color);
				}
			}			
		}
	}
}

void    ft_draw_sprites(void)
{
	float perpdistance;
	float distanceprojplane;
	float projectedspriteheight;
	t_sprite *beg;
	
	beg = g_sprites;
    while (beg)
	{
		perpdistance = beg->distance * cos(beg->angle - player.rotationangle);
		distanceprojplane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		projectedspriteheight = (TILE_SIZE / perpdistance) * distanceprojplane;
        if (projectedspriteheight <= (WINDOW_WIDTH * 2))
        	ft_draw_sprite(beg->num_ray - (projectedspriteheight / 2),
			(WINDOW_HEIGHT / 2) - (projectedspriteheight / 2),
			projectedspriteheight , beg->distance);
		beg = beg->next;
	}
	ft_lstclear();
}

int     get_ray_hit_sp(float s_x, float s_y)
{
    double   alpha;
    t_vector v_ray1;
    t_vector v_sp;

    v_ray1.x = rays[0].wallhitx - player.x;
    v_ray1.y = rays[0].wallhity - player.y;
    v_sp.x = s_x - player.x;
    v_sp.y = s_y - player.y;
    alpha = -atan2(v_ray1.y, v_ray1.x) + atan2(v_sp.y, v_sp.x);
    if (alpha > M_PI)
        alpha -= M_PI * 2;
    else if (alpha < -M_PI)
        alpha += M_PI * 2;
    return ((NUM_RAYS / FOV_ANGLE ) * alpha);
}

void    ft_fill_sprite(TMP_SPRITE	tmp_sprite)
{
	int num_ray;
	float angle;
	
    if (!ft_sprite_exist(tmp_sprite.index_x, tmp_sprite.index_y))
	{
		num_ray = get_ray_hit_sp(tmp_sprite.hit_x, tmp_sprite.hit_y);
		angle = normalizeangle(player.rotationangle - FOV_ANGLE / 2) + ( num_ray * (FOV_ANGLE / NUM_RAYS));
		ft_new_sprite(tmp_sprite, num_ray, angle);
	}
}