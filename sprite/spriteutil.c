/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriteutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:20:34 by razaha            #+#    #+#             */
/*   Updated: 2020/11/25 19:25:27 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_sprite_clear(void)
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

void	ft_swap_list(t_sprite **current, t_sprite **index)
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

void	ft_sprite_add_sorted(t_sprite *new)
{
	t_sprite	*temp;

	temp = g_sprites;
	if (!g_sprites)
		g_sprites = new;
	else
	{
		if (new->distance >= g_sprites->distance)
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

void	ft_new_sprite(t_tmp_sprite tmp_sprite, int num_ray, float angle)
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
