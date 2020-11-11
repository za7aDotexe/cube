/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:20:34 by razaha            #+#    #+#             */
/*   Updated: 2020/11/11 20:43:18 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void		ft_draw_sprite(int x, int y, int scale)
{
	float i;
	float j;

	i = 0;
	j = 0;
	while (j++ <= scale)
	{
		i = 0;
		while (i++ <= scale)
		{
			if ((x + (int)i - 1) >= 0 && (x + (int)i - 1) < WINDOW_WIDTH &&
                (y + (int)j - 1) >= 0 && (y + (int)j - 1) < WINDOW_HEIGHT &&
				(rays[x + (int)i - 1].foundhorspritehit || rays[x + (int)i - 1].foundverspritehit))
			{
				int color = ft_get_pixel(g_textures[4].width * (i / scale), g_textures[4].height * (j / scale));
				// int color = i + 300;
				if (color && color != -1)
					ft_img_pixel_put_3d(x + (int)i - 1, y + (int)j - 1, color);
			}
		}
	}
}

void	ft_lstclear(void)
{
	t_sprite *temp;
	t_sprite *beg;

	if (!g_sprites)
		return ;
	beg = g_sprites;
	while (beg)
	{
		temp = beg;
		beg = beg->next;
		free(temp);
	}
	g_sprites = NULL;
}

void    ft_draw_sprites(void)
{
	int i = 0;
	t_sprite *beg;
	beg = g_sprites;
    while (beg)
	{
        ft_draw_sprite(beg->x, beg->y, beg->scale);
		beg = beg->next;
		i++;
	}
	ft_lstclear();
}

t_sprite	*ft_new_sprite(int x, int y, int px, int py, int scale)
{
	t_sprite *new_sprite;

	if (!(new_sprite = malloc(sizeof(t_sprite))))
		return (NULL);
	new_sprite->x = x;
    new_sprite->y = y;
	new_sprite->px = px;
    new_sprite->py = py;
    new_sprite->scale = scale;
	new_sprite->next = NULL;
	return (new_sprite);
}

void	ft_sprite_add_sorted(t_sprite **sprites, t_sprite *new)
{
    t_sprite *temp;
    temp = *sprites;
    
	if (!(*sprites))	
		*sprites = new;
	else
	{
        if(new->scale <= (*sprites)->scale)
        {
		    new->next = *sprites;
		    *sprites = new;
        }
        else
        {
            while (temp->next && new->scale >= temp->next->scale)
		        temp = temp->next;
            new->next = temp->next;
            temp->next = new;
        }
	}
}

int		ft_sprite_exist(int px, int py)
{
	t_sprite *temp;

	temp = g_sprites;
	while (temp)
	{
		if ((temp->px == px) && (temp->py == py))
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void    ft_fill_sprite(int stripid, int sx, int sy)
{
    		float pang;
			float ang;
			float dang;
			float x;
			int y;
			int scale;
            t_sprite *new;

			player.rotationangle = normalizeangle(player.rotationangle);
			pang = player.rotationangle * 180. / PI;
			ang = ft_get_angleabc((t_vector) {player.x + 10, player.y},
									(t_vector) {player.x, player.y},
									(t_vector) {sx * TILE_SIZE + 16, sy * TILE_SIZE + 16});
			pang = pang > 180. ? pang - 360. : pang;
			ang = ang > 180. ? ang - 360. : ang;
			dang = pang - ang;
			dang = dang > 180 ? dang - 360. : dang;
			dang = dang < -180 ? dang + 360. : dang;
			x = ((dang) / ((FOV_ANGLE / 2) * 180 / PI)) * (WINDOW_WIDTH / 2);
			scale = (64 / (cos((dang) * PI / 180) * ft_distbpoints(player.x , player.y, sx * TILE_SIZE, sy * TILE_SIZE)))* 277;
			y = (WINDOW_HEIGHT - scale) / 2;
            if (!ft_sprite_exist(sx, sy))
			{
				new = ft_new_sprite((WINDOW_WIDTH - scale) / 2 - (int)x, y, sx, sy, scale);
            	ft_sprite_add_sorted(&g_sprites, new);
			}
}