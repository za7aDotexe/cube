/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:20:34 by razaha            #+#    #+#             */
/*   Updated: 2020/11/14 17:54:40 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"


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

void	ft_swap_list(t_sprite **current ,t_sprite **index)
{
	t_sprite *temp;
	temp = *current;
	
	
	(*current)->x = (*index)->x;
	(*current)->y = (*index)->y;
	(*current)->index_x = (*index)->index_x;
	(*current)->index_y = (*index)->index_y;
	(*current)->distance = (*index)->distance;
	(*current)->num_ray = (*index)->num_ray;
	(*current)->angle = (*index)->angle;


	(*index)->x = temp->x;
	(*index)->y = temp->y;
	(*index)->index_x = temp->index_x;
	(*index)->index_y = temp->index_y;
	(*index)->distance = temp->distance;	
	(*index)->num_ray = temp->num_ray;
	(*index)->angle = temp->angle;

}


void		ft_draw_sprite(int x, int y, int scale, int distance)
{
	float i;
	float j;

	i = 0;
	while (i++ <= scale)
	{
		if ((x + i) < NUM_RAYS && (x + i) > 0 && rays[x + (int)i].walldistance > distance)
		{
			j = 0;
			while (j++ <= scale)
			{
				if ((x + (int)i - 1) > 0 && (x + (int)i - 1) < WINDOW_WIDTH &&
					(y + (int)j - 1) > 0 && (y + (int)j - 1) < WINDOW_HEIGHT)
				{
					int color = ft_get_pixel(g_textures[4].width * (i / scale), g_textures[4].height * (j / scale));
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
	int i = 0;
	t_sprite *beg;
	beg = g_sprites;
	
    while (beg)
	{
		perpdistance = beg->distance * cos(beg->angle - player.rotationangle);
		distanceprojplane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		projectedspriteheight = (TILE_SIZE / perpdistance) * distanceprojplane;
        if (projectedspriteheight <= (WINDOW_WIDTH * 2))
        	ft_draw_sprite(beg->num_ray - (projectedspriteheight / 2), (WINDOW_HEIGHT / 2) - (projectedspriteheight / 2), projectedspriteheight , beg->distance);
		beg = beg->next;
		i++;
	}
	ft_lstclear();
}

void	ft_sprite_add_sorted(t_sprite *new)
{
    t_sprite *temp;
    temp = g_sprites;
    
	if (!g_sprites)	
		g_sprites = new;
	else
	{
        if(new->distance >= g_sprites->distance)
        {
		    new->next = g_sprites;
		    g_sprites = new;
        }
        else
        {
            while (temp->next && new->distance <= temp->next->distance)
		        temp = temp->next;
            new->next = temp->next;
            temp->next = new;
        }
	}
}

void	ft_new_sprite(TMP_SPRITE tmp_sprite, int num_ray, float angle)
{
	t_sprite *new_sprite;
	
	new_sprite = malloc(sizeof(t_sprite));
	new_sprite->x = tmp_sprite.hit_x;
    new_sprite->y = tmp_sprite.hit_y;
	new_sprite->index_x = tmp_sprite.index_x;
    new_sprite->index_y = tmp_sprite.index_y;
    new_sprite->distance = tmp_sprite.distance;
	new_sprite->num_ray = num_ray;
    new_sprite->angle = angle;
	new_sprite->next = NULL; 
	ft_sprite_add_sorted(new_sprite);
}

int		ft_sprite_exist(int index_x, int index_y)
{
	t_sprite *temp;

	temp = g_sprites;
	while (temp)
	{
		if ((temp->index_x == index_x) && (temp->index_y == index_y))
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
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