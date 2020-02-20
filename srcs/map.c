/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:07:04 by razaha            #+#    #+#             */
/*   Updated: 2020/02/20 23:05:32 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"
/*
void	ft_rendermap(void)
{
	int i;
	int j;
	float tilex;
	float tiley;

	i = 0;
	j = 0;

	tilex = 0;
	tiley = 0;
	while (j++ < MAP_NUM_ROWS)
	{
		i = 0;
		while (i++ < MAP_NUM_COLS)
		{
			tiley = (j - 1) * TILE_SIZE;
			tilex = (i - 1) * TILE_SIZE;
			if (map[j - 1][i - 1])
				ft_draw_square(
						tilex * MINIMAP_SCALE_FACTOR,
						tiley * MINIMAP_SCALE_FACTOR,
						TILE_SIZE * MINIMAP_SCALE_FACTOR,
						TILE_SIZE * MINIMAP_SCALE_FACTOR,
						twod_img
						);
		}
	}
}

int maphaswallat(float x,float y)
{
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return true;
	int mapgridindexx = floor(x / TILE_SIZE);
	int mapgridindexy = floor(y / TILE_SIZE);
	return (map[mapgridindexy][mapgridindexx] != 0);
}
*/
