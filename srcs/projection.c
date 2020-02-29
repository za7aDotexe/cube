/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:44:33 by razaha            #+#    #+#             */
/*   Updated: 2020/02/29 22:05:07 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_texture(int offx, int offy)
{
	// printf("offx--> %d\n offy-->%d\n", offx, offy);
	// return (0);
	
	return (textu.data[textu.width * offy + offx  *2]);
}

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

	
	int texttureOffestX;
	int texttureOffestY;
	int distancefromtop;
	
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

		if (rays[i].washitvertical)
			texttureOffestX = (int)rays[i].wallhity % TILE_SIZE;
		else
			texttureOffestX = (int)rays[i].wallhitx % TILE_SIZE;
		
		j = walltoppixel;
		while (j++ < wallbottompixel)
		{
			distancefromtop = j + (wallstripheight / 2) - (WINDOW_HEIGHT / 2);
			texttureOffestY = distancefromtop * ((float)TEXTURE_HEIGHT / wallstripheight); 
			
			// ft_img_pixel_put_3d(threed_img, i - 1, j - 1,
			// 		rays[i - 1].washitvertical ? 0x0BE597 : 0xEF7A9D);
			ft_img_pixel_put_3d(threed_img, i - 1, j - 1, ft_texture(texttureOffestX, texttureOffestY));
		}
		j = wallbottompixel;
		while (j++ < WINDOW_HEIGHT)
			ft_img_pixel_put_3d(threed_img, i - 1, j - 1, 0xFCD871);
	}
}
