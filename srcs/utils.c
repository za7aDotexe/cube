/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:24:52 by razaha            #+#    #+#             */
/*   Updated: 2020/03/01 17:16:28 by razaha           ###   ########.fr       */
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
	line.dx = abs(x2 - x1);
	line.sx = x1 < x2 ? 1 : -1;
	line.dy = abs(y2 - y1);
	line.sy = y1 < y2 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	line.e2 = 0;
	while (1)
	{
		ft_img_pixel_put_2d(x1, y1, 0xffff00);
		if (x1 == x2 && y1 == y2)
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			x1 += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			y1 += line.sy;
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
	if (x < WINDOW_WIDTH * MINIMAP_SCALE_FACTOR && y < WINDOW_HEIGHT *
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
