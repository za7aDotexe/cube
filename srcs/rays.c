/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:17:40 by razaha            #+#    #+#             */
/*   Updated: 2020/11/29 19:14:02 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	castray2(float rayangle, int stripid)
{
	if (g_inter.verhitdistance < g_inter.horhitdistance)
	{
		g_rays[stripid].walldistance = g_inter.verhitdistance;
		g_rays[stripid].wallhitx = g_inter.verwallhitx;
		g_rays[stripid].wallhity = g_inter.verwallhity;
		g_rays[stripid].wallhitcontent = g_inter.verwallcontent;
		g_rays[stripid].washitverical = TRUE;
	}
	else
	{
		g_rays[stripid].walldistance = g_inter.horhitdistance;
		g_rays[stripid].wallhitx = g_inter.horwallhitx;
		g_rays[stripid].wallhity = g_inter.horwallhity;
		g_rays[stripid].wallhitcontent = g_inter.horwallcontent;
		g_rays[stripid].washitverical = FALSE;
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
	g_inter.spr = 0;
	g_inter.tmp_sprite = (t_tmp_sprite *)(malloc(g_num_sp * NUM_RAYS
	* sizeof(t_tmp_sprite *)));
	horinter(rayangle);
	verinter(rayangle);
	g_inter.horhitdistance = g_inter.fndhorwallhit ? ft_dstbpoints(
		g_player.x, g_player.y, g_inter.horwallhitx, g_inter.horwallhity)
	: INT_MAX;
	g_inter.verhitdistance = g_inter.fndverwallhit ? ft_dstbpoints(
		g_player.x, g_player.y, g_inter.verwallhitx, g_inter.verwallhity)
	: INT_MAX;
	castray2(rayangle, stripid);
	while (i++ < g_inter.spr)
		ft_fill_sprite(g_inter.tmp_sprite[i - 1]);
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
