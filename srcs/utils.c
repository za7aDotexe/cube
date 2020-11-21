/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:24:52 by razaha            #+#    #+#             */
/*   Updated: 2020/11/19 18:38:11 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int			ft_get_pixel(int x, int y)
{
	int	*p;
	int i;

	if (x >= g_textures[4].width || x < 0 || y >= g_textures[4].height || y < 0)
		return (-1);
	i = x + (g_textures[4].sizeline / 4) * y;
	p = (int *)g_textures[4].data;
	return (p[i]);
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

int			rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
