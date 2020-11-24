/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:21:38 by razaha            #+#    #+#             */
/*   Updated: 2020/11/24 19:23:03 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

float	normalizeangle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	ft_distbpoints(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float	ft_get_angleabc(t_vector a, t_vector b, t_vector c)
{
	float		ang;
	float		dot;
	float		cross;
	float		alpha;

	g_ab.x = b.x - a.x;
	g_ab.y = b.y - a.y;
	g_cb.x = b.x - c.x;
	g_cb.y = b.y - c.y;
	cross = (g_ab.x * g_cb.y - g_ab.y * g_cb.x);
	dot = (g_ab.x * g_cb.x + g_ab.y * g_cb.y);
	alpha = atan2(cross, dot);
	ang = alpha * 180. / PI + 0.5;
	return (ang < 0 ? ang + 360 : ang);
}
