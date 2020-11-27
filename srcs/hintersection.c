/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hintersection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:07:16 by razaha            #+#    #+#             */
/*   Updated: 2020/11/27 12:26:37 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	horspinter(void)
{
	if (mapinter(g_inter.xtocheck, g_inter.ytocheck) == '2')
	{
		g_inter.tmp_sprite[g_inter.i_sp].index_x = g_inter.xtocheck / TILE_SIZE;
		g_inter.tmp_sprite[g_inter.i_sp].index_y =
		(g_inter.ytocheck) / TILE_SIZE;
		g_inter.tmp_sprite[g_inter.i_sp].hit_x =
		(g_inter.tmp_sprite[g_inter.i_sp].index_x * TILE_SIZE)
		+ (TILE_SIZE / 2);
		g_inter.tmp_sprite[g_inter.i_sp].hit_y =
		(g_inter.tmp_sprite[g_inter.i_sp].index_y * TILE_SIZE)
		+ (TILE_SIZE / 2);
		g_inter.tmp_sprite[g_inter.i_sp].distance = ft_dstbpoints(g_player.x,
		g_player.y, g_inter.tmp_sprite[g_inter.i_sp].hit_x,
		g_inter.tmp_sprite[g_inter.i_sp].hit_y);
		g_inter.i_sp++;
	}
}

void	horinter2(int stripid)
{
	while (g_inter.nexthortouchx >= 0
	&& g_inter.nexthortouchx <= g_cols * TILE_SIZE
	&& g_inter.nexthortouchy >= 0
	&& g_inter.nexthortouchy <= g_rows * TILE_SIZE)
	{
		g_inter.xtocheck = g_inter.nexthortouchx;
		g_inter.ytocheck = g_inter.nexthortouchy +
		(g_inter.israyfacingup ? -1 : 0);
		horspinter();
		if (mapinter(g_inter.xtocheck, g_inter.ytocheck) == '1')
		{
			g_inter.fndhorwallhit = TRUE;
			g_inter.horwallhitx = g_inter.nexthortouchx;
			g_inter.horwallhity = g_inter.nexthortouchy;
			g_inter.horwallcontent =
				g_map[(int)floor(g_inter.ytocheck / TILE_SIZE)]
				[(int)floor(g_inter.xtocheck / TILE_SIZE)];
			break ;
		}
		else
		{
			g_inter.nexthortouchx += g_inter.xstep;
			g_inter.nexthortouchy += g_inter.ystep;
		}
	}
}

void	horinter(float rayangle, int stripid)
{
	g_inter.fndhorwallhit = FALSE;
	g_inter.horwallhitx = 0;
	g_inter.horwallhity = 0;
	g_inter.horwallcontent = 0;
	g_inter.yintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	g_inter.yintercept += g_inter.israyfacingdown ? TILE_SIZE : 0;
	g_inter.xintercept = g_player.x
	+ (g_inter.yintercept - g_player.y) / tan(rayangle);
	g_inter.ystep = TILE_SIZE;
	g_inter.ystep *= g_inter.israyfacingup ? -1 : 1;
	g_inter.xstep = TILE_SIZE / tan(rayangle);
	g_inter.xstep *= (g_inter.israyfacingleft && g_inter.xstep > 0) ? -1 : 1;
	g_inter.xstep *= (g_inter.israyfacingright && g_inter.xstep < 0) ? -1 : 1;
	g_inter.nexthortouchx = g_inter.xintercept;
	g_inter.nexthortouchy = g_inter.yintercept;
	horinter2(stripid);
}
