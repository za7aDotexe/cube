/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:17:40 by razaha            #+#    #+#             */
/*   Updated: 2020/03/08 00:06:21 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	castray2(float rayangle, int stripid)
{
	if (inter.verthitdistance < inter.horzhitdistance)
	{
		rays[stripid].walldistance = inter.verthitdistance;
		rays[stripid].spritedistance = inter.vertsphitdistance;
		rays[stripid].wallhitx = inter.vertwallhitx;
		rays[stripid].wallhity = inter.vertwallhity;
		rays[stripid].spritehitx = inter.verspritehitx;
		rays[stripid].spritehity = inter.verspritehity;
		rays[stripid].wallhitcontent = inter.vertwallcontent;
		rays[stripid].washitvertical = true;
	}
	else
	{
		rays[stripid].walldistance = inter.horzhitdistance;
		rays[stripid].spritedistance = inter.horzsphitdistance;
		rays[stripid].wallhitx = inter.horzwallhitx;
		rays[stripid].wallhity = inter.horzwallhity;
		rays[stripid].spritehitx = inter.horzspritehitx;
		rays[stripid].spritehity = inter.horzspritehity;
		rays[stripid].wallhitcontent = inter.horzwallcontent;
		rays[stripid].washitvertical = false;
	}
	rays[stripid].rayangle = rayangle;
	rays[stripid].israyfacingdown = inter.israyfacingdown;
	rays[stripid].israyfacingup = inter.israyfacingup;
	rays[stripid].israyfacingright = inter.israyfacingright;
	rays[stripid].israyfacingleft = inter.israyfacingleft;
}

void	castray(float rayangle, int stripid)
{
	rayangle = normalizeangle(rayangle);
	inter.israyfacingdown = rayangle > 0 && rayangle < PI;
	inter.israyfacingup = !inter.israyfacingdown;
	inter.israyfacingright = rayangle < PI * 0.5 || rayangle > PI * 1.5;
	inter.israyfacingleft = !inter.israyfacingright;
	horinter(rayangle);
	verinter(rayangle);
	inter.horzhitdistance = inter.foundhorzwallhit ? ft_distbpoints(player.x,
			player.y, inter.horzwallhitx, inter.horzwallhity) : INT_MAX;
	inter.verthitdistance = inter.foundvertwallhit ? ft_distbpoints(player.x,
			player.y, inter.vertwallhitx, inter.vertwallhity) : INT_MAX;
	inter.horzsphitdistance = inter.foundhorspritehit ? ft_distbpoints(player.x,
			player.y, inter.horzspritehitx, inter.horzspritehity) : INT_MAX;
	inter.vertsphitdistance = inter.foundverspritehit ? ft_distbpoints(player.x,
			player.y, inter.verspritehitx, inter.verspritehity) : INT_MAX;
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
