/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:17:40 by razaha            #+#    #+#             */
/*   Updated: 2020/11/24 19:21:15 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	castray2(float rayangle, int stripid)
{
	if (g_inter.verthitdistance < g_inter.horzhitdistance)
	{
		g_rays[stripid].walldistance = g_inter.verthitdistance;
		g_rays[stripid].wallhitx = g_inter.vertwallhitx;
		g_rays[stripid].wallhity = g_inter.vertwallhity;
		g_rays[stripid].wallhitcontent = g_inter.vertwallcontent;
		g_rays[stripid].washitvertical = TRUE;
	}
	else
	{
		g_rays[stripid].walldistance = g_inter.horzhitdistance;
		g_rays[stripid].wallhitx = g_inter.horzwallhitx;
		g_rays[stripid].wallhity = g_inter.horzwallhity;
		g_rays[stripid].wallhitcontent = g_inter.horzwallcontent;
		g_rays[stripid].washitvertical = FALSE;
	}
	g_rays[stripid].rayangle = rayangle;
	g_rays[stripid].israyfacingdown = g_inter.israyfacingdown;
	g_rays[stripid].israyfacingup = g_inter.israyfacingup;
	g_rays[stripid].israyfacingright = g_inter.israyfacingright;
	g_rays[stripid].israyfacingleft = g_inter.israyfacingleft;
}

void	castray(float rayangle, int stripid)
{
	int i;

	i = 0;
	rayangle = normalizeangle(rayangle);
	g_inter.israyfacingdown = rayangle > 0 && rayangle < PI;
	g_inter.israyfacingup = !g_inter.israyfacingdown;
	g_inter.israyfacingright = rayangle < PI * 0.5 || rayangle > PI * 1.5;
	g_inter.israyfacingleft = !g_inter.israyfacingright;
	g_inter.i_sp = 0;
	g_inter.tmp_sprite = (t_TMP_SPRITE *)(malloc(num_sp * NUM_RAYS
	* sizeof(t_TMP_SPRITE *)));
	horinter(rayangle, stripid);
	verinter(rayangle, stripid);
	g_inter.horzhitdistance = g_inter.foundhorzwallhit ? ft_distbpoints(g_player.x,
			g_player.y, g_inter.horzwallhitx, g_inter.horzwallhity) : INT_MAX;
	g_inter.verthitdistance = g_inter.foundvertwallhit ? ft_distbpoints(g_player.x,
			g_player.y, g_inter.vertwallhitx, g_inter.vertwallhity) : INT_MAX;
	castray2(rayangle, stripid);
	while (i++ < g_inter.i_sp)
	{
		if (g_inter.tmp_sprite[i - 1].distance <= g_rays[stripid].walldistance)
			ft_fill_sprite(g_inter.tmp_sprite[i - 1]);
	}
	if (g_inter.tmp_sprite)
		free(g_inter.tmp_sprite);
}

void	ft_castallrays(void)
{
	int		stripid;
	float	rayangle;

	rayangle = g_player.rotationangle - (FOV_ANGLE / 2.0);
	stripid = 0;
	while (stripid < NUM_RAYS)
	{
		castray(rayangle, stripid);
		rayangle += FOV_ANGLE / (double)NUM_RAYS;
		stripid++;
	}
}
