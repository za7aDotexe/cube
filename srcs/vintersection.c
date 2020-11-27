/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vintersection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:54:34 by razaha            #+#    #+#             */
/*   Updated: 2020/11/27 12:06:34 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	verspinter(void)
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

void	verinter2(int stripid)
{
	while (g_inter.nextvertouchx >= 0
	&& g_inter.nextvertouchx <= g_cols * TILE_SIZE
	&& g_inter.nextvertouchy >= 0
	&& g_inter.nextvertouchy <= g_rows * TILE_SIZE)
	{
		g_inter.xtocheck = g_inter.nextvertouchx +
		(g_inter.israyfacingleft ? -1 : 0);
		g_inter.ytocheck = g_inter.nextvertouchy;
		verspinter();
		if (mapinter(g_inter.xtocheck, g_inter.ytocheck) == '1')
		{
			g_inter.fndverwallhit = TRUE;
			g_inter.verwallhitx = g_inter.nextvertouchx;
			g_inter.verwallhity = g_inter.nextvertouchy;
			g_inter.verwallcontent =
				g_map[(int)floor(g_inter.ytocheck / TILE_SIZE)]
				[(int)floor(g_inter.xtocheck / TILE_SIZE)];
			break ;
		}
		else
		{
			g_inter.nextvertouchx += g_inter.xstep;
			g_inter.nextvertouchy += g_inter.ystep;
		}
	}
}

void	verinter(float rayangle, int stripid)
{
	g_inter.fndverwallhit = FALSE;
	g_inter.verwallhitx = 0;
	g_inter.verwallhity = 0;
	g_inter.verwallcontent = 0;
	g_inter.xintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	g_inter.xintercept += g_inter.israyfacingright ? TILE_SIZE : 0;
	g_inter.yintercept = g_player.y +
	(g_inter.xintercept - g_player.x) * tan(rayangle);
	g_inter.xstep = TILE_SIZE;
	g_inter.xstep *= g_inter.israyfacingleft ? -1 : 1;
	g_inter.ystep = TILE_SIZE * tan(rayangle);
	g_inter.ystep *= (g_inter.israyfacingup
	&& g_inter.ystep > 0) ? -1 : 1;
	g_inter.ystep *= (g_inter.israyfacingdown
	&& g_inter.ystep < 0) ? -1 : 1;
	g_inter.nextvertouchx = g_inter.xintercept;
	g_inter.nextvertouchy = g_inter.yintercept;
	verinter2(stripid);
}
