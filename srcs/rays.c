/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:17:40 by razaha            #+#    #+#             */
/*   Updated: 2020/11/14 17:43:41 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	castray2(float rayangle, int stripid)
{
	if (inter.verthitdistance < inter.horzhitdistance)
	{
		rays[stripid].walldistance = inter.verthitdistance;
		rays[stripid].wallhitx = inter.vertwallhitx;
		rays[stripid].wallhity = inter.vertwallhity;
		rays[stripid].wallhitcontent = inter.vertwallcontent;
		rays[stripid].washitvertical = true;
	}
	else
	{
		rays[stripid].walldistance = inter.horzhitdistance;
		rays[stripid].wallhitx = inter.horzwallhitx;
		rays[stripid].wallhity = inter.horzwallhity;
		rays[stripid].wallhitcontent = inter.horzwallcontent;
		rays[stripid].washitvertical = false;
	}
	rays[stripid].rayangle = rayangle;
	rays[stripid].israyfacingdown = inter.israyfacingdown;
	rays[stripid].israyfacingup = inter.israyfacingup;
	rays[stripid].israyfacingright = inter.israyfacingright;
	rays[stripid].israyfacingleft = inter.israyfacingleft;

	int i = 0;

	while (i++ < inter.i_sp)
	{
		if (inter.tmp_sprite[i-1].distance <= rays[stripid].walldistance)
			ft_fill_sprite(inter.tmp_sprite[i-1]);
	}
	
	// if (inter.tmp_sprite)
	// 	free(inter.tmp_sprite);
}

void	castray(float rayangle, int stripid)
{
	rayangle = normalizeangle(rayangle);
	inter.israyfacingdown = rayangle > 0 && rayangle < PI;
	inter.israyfacingup = !inter.israyfacingdown;
	inter.israyfacingright = rayangle < PI * 0.5 || rayangle > PI * 1.5;
	inter.israyfacingleft = !inter.israyfacingright;
	inter.i_sp = 0;
	inter.tmp_sprite = (TMP_SPRITE *)(malloc(100 /*change this with g nu of spr*/ * 2 * sizeof(TMP_SPRITE *)));
	horinter(rayangle, stripid);
	verinter(rayangle, stripid);
	inter.horzhitdistance = inter.foundhorzwallhit ? ft_distbpoints(player.x,
			player.y, inter.horzwallhitx, inter.horzwallhity) : INT_MAX;
	inter.verthitdistance = inter.foundvertwallhit ? ft_distbpoints(player.x,
			player.y, inter.vertwallhitx, inter.vertwallhity) : INT_MAX;
	castray2(rayangle, stripid);
}

void	ft_castallrays(void)
{
	int		stripid;
	float	rayangle;

	rayangle = player.rotationangle - (FOV_ANGLE / 2.0);
	stripid = 0;
	
	while (stripid < NUM_RAYS)
	{
		castray(rayangle, stripid);
		rayangle += FOV_ANGLE / (double)NUM_RAYS;
		stripid++;
	}
}

void	ft_renderrays(void)
{
	int i;

	i = 0;
	while (i++ < NUM_RAYS)
	{
		ft_draw_line(
				player.x * MINIMAP_SCALE_FACTOR,
				player.y * MINIMAP_SCALE_FACTOR,
				rays[i - 1].wallhitx * MINIMAP_SCALE_FACTOR,
				rays[i - 1].wallhity * MINIMAP_SCALE_FACTOR);
	}
}