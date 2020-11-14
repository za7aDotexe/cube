/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:24:52 by razaha            #+#    #+#             */
/*   Updated: 2020/11/14 19:55:14 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_draw_square(float x, float y, float w, float h)
{
	float i;
	float j;

	i = 0;
	j = 0;
	while (j++ <= h)
	{
		i = 0;
		while (i++ <= w)
			ft_img_pixel_put_2d(x + i - 1, y + j - 1, 0xFF0000);
	}
}

void	ft_draw_line(int x1, int y1, int x2, int y2)
{
	g_line.dx = abs(x2 - x1);
	g_line.sx = x1 < x2 ? 1 : -1;
	g_line.dy = abs(y2 - y1);
	g_line.sy = y1 < y2 ? 1 : -1;
	g_line.err = (g_line.dx > g_line.dy ? g_line.dx : -g_line.dy) / 2;
	g_line.e2 = 0;
	while (1)
	{
		ft_img_pixel_put_2d(x1, y1, 0xffff00);
		if (x1 == x2 && y1 == y2)
			break ;
		g_line.e2 = g_line.err;
		if (g_line.e2 > -g_line.dx)
		{
			g_line.err -= g_line.dy;
			x1 += g_line.sx;
		}
		if (g_line.e2 < g_line.dy)
		{
			g_line.err += g_line.dx;
			y1 += g_line.sy;
		}
	}
}

void	ft_img_pixel_put_2d(int x, int y, int color)
{
	int *add;
	int bpp;
	int sizeline;
	int endian;
	int cord;

	add = (int *)mlx_get_data_addr(twod_img, &bpp, &sizeline, &endian);
	cord = (y * sizeline / 4 + x);
	if (x < cols * TILE_SIZE * MINIMAP_SCALE_FACTOR && y < rows * TILE_SIZE *
			MINIMAP_SCALE_FACTOR)
		add[cord] = color;
}

void	ft_img_pixel_put_3d(int x, int y, int color)
{
	int *add;
	int bpp;
	int sizeline;
	int endian;
	int cord;

	add = (int *)mlx_get_data_addr(threed_img, &bpp, &sizeline, &endian);
	cord = (y * sizeline / 4 + x);
	if (x < WINDOW_WIDTH && x >= 0 && y >= 0 && y < WINDOW_HEIGHT)
		add[cord] = color;
}
