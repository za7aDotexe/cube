/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:44:33 by razaha            #+#    #+#             */
/*   Updated: 2020/03/08 00:03:49 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void ft_projectwall(void)
{
	projec.j = 0;
	while (projec.j++ < projec.walltoppixel)
		ft_img_pixel_put_3d(projec.i - 1, projec.j - 1, 0x87ceeb);
	if (rays[projec.i].washitvertical)
		projec.texttureoffestx = (int)rays[projec.i].wallhity % TILE_SIZE;
	else
		projec.texttureoffestx = (int)rays[projec.i].wallhitx % TILE_SIZE;
	projec.j = projec.walltoppixel;
	while (projec.j++ < projec.wallbottompixel)
	{
		projec.distancefromtop = projec.j + (projec.wallstripheight / 2)
			- (WINDOW_HEIGHT / 2);
		projec.texttureoffesty = projec.distancefromtop *
			((float)TEXTURE_HEIGHT / projec.wallstripheight);
		ft_img_pixel_put_3d(projec.i - 1, projec.j - 1, textu.data[textu.width
			* projec.texttureoffesty + projec.texttureoffestx * 2]);
	}
	projec.j = projec.wallbottompixel;
	while (projec.j++ < WINDOW_HEIGHT)
		ft_img_pixel_put_3d(projec.i - 1, projec.j - 1, 0xFCD871);
}
void ft_projectsprite(void)
{
	projec.j = 0;
	while (projec.j++ < projec.wallbottompixel)
	{
		projec.distancefromtop = projec.j + (projec.wallstripheight / 2)
			- (WINDOW_HEIGHT / 2);
		projec.texttureoffesty = projec.distancefromtop *
			((float)TEXTURE_HEIGHT / projec.wallstripheight);
		ft_img_pixel_put_3d(projec.i - 1, projec.j - 1, 0x0000ff);
	}
}

void	ft_projection2(void)
{
	ft_projectwall();
	// if(rays[projec.i].wallhitcontent == 3)
	// 	ft_projectsprite();
}

void	ft_projection(void)
{
	projec.i = 0;
	while (projec.i++ < NUM_RAYS)
	{
		projec.perpdistance = rays[projec.i - 1].walldistance *
			cos(rays[projec.i - 1].rayangle - player.rotationangle);
		projec.distanceprojplane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		projec.projectedwallheight = (TILE_SIZE / projec.perpdistance)
			* projec.distanceprojplane;
		projec.wallstripheight = (int)projec.projectedwallheight;
		projec.walltoppixel = (WINDOW_HEIGHT / 2) -
			(projec.wallstripheight / 2);
		projec.walltoppixel = projec.walltoppixel < 0 ? 0
			: projec.walltoppixel;
		projec.wallbottompixel = (WINDOW_HEIGHT / 2) +
			(projec.wallstripheight / 2);
		projec.wallbottompixel = projec.wallbottompixel > WINDOW_HEIGHT ?
			WINDOW_HEIGHT : projec.wallbottompixel;
		ft_projection2();
	}
}
