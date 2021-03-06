/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:52:42 by razaha            #+#    #+#             */
/*   Updated: 2020/12/01 13:17:44 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_draw_sprite(int x, int y, int scale, int distance)
{
	int		color;
	float	i;
	float	j;

	i = 0;
	while (i++ <= scale)
	{
		if ((x + i - 1) <= NUM_RAYS && (x + i - 1) >= 0
				&& g_rays[x + (int)i - 1].walldistance >= distance)
		{
			j = 0;
			while (j++ <= scale)
			{
				if ((x + (int)i - 1) >= 0 && (x + (int)i - 1) < g_window_width
				&& (y + (int)j - 1) >= 0 && (y + (int)j - 1) < g_window_height)
				{
					color = ft_get_pixel(g_textures[4].width * (i / scale),
							g_textures[4].height * (j / scale));
					if (color != g_textures[4].data[0] && color != -1)
						ft_img_pixel_put_3d(x + i - 1, y + j - 1, color);
				}
			}
		}
	}
}

void	ft_draw_sprites(void)
{
	float		perpdistance;
	float		distanceprojplane;
	float		projectedspriteheight;
	t_sprite	*beg;

	beg = g_sprites;
	while (beg)
	{
		perpdistance = beg->distance * cos(beg->angle - g_player.rotationangle);
		distanceprojplane = (g_window_width / 2) / tan(FOV_ANGLE / 2);
		projectedspriteheight = (TILE_SIZE / perpdistance) * distanceprojplane;
		if (projectedspriteheight <= (g_window_width * 2))
			ft_draw_sprite(beg->num_ray - (projectedspriteheight / 2),
					(g_window_height / 2) - (projectedspriteheight / 2),
					projectedspriteheight, beg->distance);
		beg = beg->next;
	}
	ft_sprite_clear();
}

int		get_ray_hit_sp(float s_x, float s_y)
{
	double	alpha;

	g_ab.x = g_rays[0].wallhitx - g_player.x;
	g_ab.y = g_rays[0].wallhity - g_player.y;
	g_cb.x = s_x - g_player.x;
	g_cb.y = s_y - g_player.y;
	alpha = -atan2(g_ab.y, g_ab.x) + atan2(g_cb.y, g_cb.x);
	if (alpha > M_PI)
		alpha -= M_PI * 2;
	else if (alpha < -M_PI)
		alpha += M_PI * 2;
	return ((NUM_RAYS / FOV_ANGLE) * alpha);
}

void	ft_fill_sprite(t_tmp_sprite tmp_sprite)
{
	int		num_ray;
	float	angle;

	if (!ft_sprite_exist(tmp_sprite.index_x, tmp_sprite.index_y))
	{
		num_ray = get_ray_hit_sp(tmp_sprite.hit_x, tmp_sprite.hit_y);
		angle = normalizeangle(g_player.rotationangle - FOV_ANGLE / 2)
			+ (num_ray * (FOV_ANGLE / NUM_RAYS));
		ft_new_sprite(tmp_sprite, num_ray, angle);
	}
}
