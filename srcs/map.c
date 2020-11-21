/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1010/01/10 11:07:01 by razaha            #+#    #+#             */
/*   Updated: 2020/11/19 20:09:09 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int		maphaswallat(float x, float y)
{
	int mapgridindexx;
	int mapgridindexy;

	if (x < 0 || x >= cols * TILE_SIZE || y < 0 || y >= rows * TILE_SIZE)
		return (true);
	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	if (g_map[mapgridindexy][mapgridindexx] == '1'
	|| g_map[mapgridindexy][mapgridindexx] == '2')
		return (true);
	return (false);
}

int		mapinter(float x, float y)
{
	int mapgridindexx;
	int mapgridindexy;

	if (x < 0 || x >= cols * TILE_SIZE || y < 0 || y >= rows * TILE_SIZE)
		return (true);
	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	return (g_map[mapgridindexy][mapgridindexx]);
}
