/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:21:38 by razaha            #+#    #+#             */
/*   Updated: 2020/11/14 19:55:53 by razaha           ###   ########.fr       */
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

float		normalizeangle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float		ft_distbpoints(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float		ft_get_angleabc(t_vector a, t_vector b, t_vector c)
{
	float		ang;
	float		dot;
	float		cross;
	float		alpha;
	t_vector	ab;
	t_vector	cb;

	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	cb.x = b.x - c.x;
	cb.y = b.y - c.y;
	cross = (ab.x * cb.y - ab.y * cb.x);
	dot = (ab.x * cb.x + ab.y * cb.y);
	alpha = atan2(cross, dot);
	ang = alpha * 180. / PI + 0.5;
	return (ang < 0 ? ang + 360 : ang);
}

int			rgb_to_hex(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}
