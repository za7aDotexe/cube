/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1010/01/10 11:07:01 by razaha            #+#    #+#             */
/*   Updated: 2020/11/08 19:11:15 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"


void	ft_rendermap(void)
{
	int		i;
	int		j;
	float	tilex;
	float	tiley;

	i = 0;
	j = 0;
	tilex = 0;
	tiley = 0;
	while (j++ < rows)
	{
		i = 0;
		while (i++ < cols)
		{
			tiley = (j - 1) * TILE_SIZE;
			tilex = (i - 1) * TILE_SIZE;
			if (g_map[j - 1][i - 1] == '1' || g_map[j - 1][i - 1] == '2')
				ft_draw_square(
						tilex * MINIMAP_SCALE_FACTOR,
						tiley * MINIMAP_SCALE_FACTOR,
						TILE_SIZE * MINIMAP_SCALE_FACTOR,
						TILE_SIZE * MINIMAP_SCALE_FACTOR);
		}
	}
}

int		maphaswallat(float x, float y)
{
	int mapgridindexx;
	int mapgridindexy;

	if (x < 0 || x > cols * TILE_SIZE || y < 0 || y > rows * TILE_SIZE)
		return (true);
	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	if (g_map[mapgridindexy][mapgridindexx] == '1'
			|| g_map[mapgridindexy][mapgridindexx] == '3')
		return (true);
	return (false);
}

int		mapinter(float x, float y)
{
	int mapgridindexx;
	int mapgridindexy;

	if (x < 0 || x > cols * TILE_SIZE || y < 0 || y > rows * TILE_SIZE)
		return (true);
	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	return (g_map[mapgridindexy][mapgridindexx]);
}
