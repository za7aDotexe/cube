/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:44:33 by razaha            #+#    #+#             */
/*   Updated: 2020/02/20 22:03:14 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_projection(void)
{
	int		i;
	int		j;
	float	perpdistance;
	float	distanceprojplane;
	float	projectedwallheight;
	int		wallstripheight;
	int		walltoppixel;
	int		wallbottompixel;

	i = 0;
	while (i++ < NUM_RAYS)
	{
		perpdistance = rays[i - 1].distance * cos(rays[i - 1].rayangle -
				player.rotationangle);
		distanceprojplane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		projectedwallheight = (TILE_SIZE / perpdistance) * distanceprojplane;
		wallstripheight = (int)projectedwallheight;
		walltoppixel = (WINDOW_HEIGHT / 2) - (wallstripheight / 2);
		walltoppixel = walltoppixel < 0 ? 0 : walltoppixel;
		wallbottompixel = (WINDOW_HEIGHT / 2) + (wallstripheight / 2);
		wallbottompixel = wallbottompixel > WINDOW_HEIGHT ? WINDOW_HEIGHT :
			wallbottompixel;
		j = 0;
		while (j++ < walltoppixel)
			ft_img_pixel_put_3d(threed_img, i - 1, j - 1, 0x87ceeb);
		j = walltoppixel;
		while (j++ < wallbottompixel)
			ft_img_pixel_put_3d(threed_img, i - 1, j - 1,
					rays[i - 1].washitvertical ? 0x0BE597 : 0xEF7A9D);
		j = wallbottompixel;
		while (j++ < WINDOW_HEIGHT)
			ft_img_pixel_put_3d(threed_img, i - 1, j - 1, 0xFCD871);
	}
}
