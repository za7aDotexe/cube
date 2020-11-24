/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vintersection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:54:34 by razaha            #+#    #+#             */
/*   Updated: 2020/11/24 19:46:17 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	verspinter(void)
{
	if (mapinter(g_inter.xtocheck, g_inter.ytocheck) == '2')
	{
		g_inter.tmp_sprite[g_inter.i_sp].index_x = g_inter.xtocheck / TILE_SIZE;
		g_inter.tmp_sprite[g_inter.i_sp].index_y = (g_inter.ytocheck) / TILE_SIZE;
		g_inter.tmp_sprite[g_inter.i_sp].hit_x =
		(g_inter.tmp_sprite[g_inter.i_sp].index_x * TILE_SIZE) + (TILE_SIZE / 2);
		g_inter.tmp_sprite[g_inter.i_sp].hit_y =
		(g_inter.tmp_sprite[g_inter.i_sp].index_y * TILE_SIZE) + (TILE_SIZE / 2);
		g_inter.tmp_sprite[g_inter.i_sp].distance = ft_distbpoints(g_player.x,
		g_player.y, g_inter.tmp_sprite[g_inter.i_sp].hit_x,
		g_inter.tmp_sprite[g_inter.i_sp].hit_y);
		g_inter.i_sp++;
	}
}

void	verinter2(int stripid)
{
	while (g_inter.nextverttouchx >= 0
	&& g_inter.nextverttouchx <= g_cols * TILE_SIZE
	&& g_inter.nextverttouchy >= 0 && g_inter.nextverttouchy <= g_rows * TILE_SIZE)
	{
		g_inter.xtocheck = g_inter.nextverttouchx +
		(g_inter.israyfacingleft ? -1 : 0);
		g_inter.ytocheck = g_inter.nextverttouchy;
		verspinter();
		if (mapinter(g_inter.xtocheck, g_inter.ytocheck) == '1')
		{
			g_inter.foundvertwallhit = TRUE;
			g_inter.vertwallhitx = g_inter.nextverttouchx;
			g_inter.vertwallhity = g_inter.nextverttouchy;
			g_inter.vertwallcontent =
				g_map[(int)floor(g_inter.ytocheck / TILE_SIZE)]
				[(int)floor(g_inter.xtocheck / TILE_SIZE)];
			break ;
		}
		else
		{
			g_inter.nextverttouchx += g_inter.xstep;
			g_inter.nextverttouchy += g_inter.ystep;
		}
	}
}

void	verinter(float rayangle, int stripid)
{
	g_inter.foundvertwallhit = FALSE;
	g_inter.vertwallhitx = 0;
	g_inter.vertwallhity = 0;
	g_inter.vertwallcontent = 0;
	g_inter.xintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	g_inter.xintercept += g_inter.israyfacingright ? TILE_SIZE : 0;
	g_inter.yintercept = g_player.y + (g_inter.xintercept - g_player.x) * tan(rayangle);
	g_inter.xstep = TILE_SIZE;
	g_inter.xstep *= g_inter.israyfacingleft ? -1 : 1;
	g_inter.ystep = TILE_SIZE * tan(rayangle);
	g_inter.ystep *= (g_inter.israyfacingup && g_inter.ystep > 0) ? -1 : 1;
	g_inter.ystep *= (g_inter.israyfacingdown && g_inter.ystep < 0) ? -1 : 1;
	g_inter.nextverttouchx = g_inter.xintercept;
	g_inter.nextverttouchy = g_inter.yintercept;
	verinter2(stripid);
}
