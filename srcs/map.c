/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1010/01/10 11:07:01 by razaha            #+#    #+#             */
/*   Updated: 2020/11/24 19:46:17 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int		maphaswallat(float x, float y)
{
	int mapgridindexx;
	int mapgridindexy;

	if (x < 0 || x >= g_cols * TILE_SIZE || y < 0 || y >= g_rows * TILE_SIZE)
		return (TRUE);
	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	if (g_map[mapgridindexy][mapgridindexx] == '1'
	|| g_map[mapgridindexy][mapgridindexx] == '2')
		return (TRUE);
	return (FALSE);
}

int		mapinter(float x, float y)
{
	int mapgridindexx;
	int mapgridindexy;

	if (x < 0 || x >= g_cols * TILE_SIZE || y < 0 || y >= g_rows * TILE_SIZE)
		return (TRUE);
	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	return (g_map[mapgridindexy][mapgridindexx]);
}
