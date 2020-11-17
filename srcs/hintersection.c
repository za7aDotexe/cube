/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hintersection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:07:16 by razaha            #+#    #+#             */
/*   Updated: 2020/11/15 20:46:26 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	horspinter(void)
{
	if (mapinter(inter.xtocheck, inter.ytocheck) == '3')
	{
		inter.tmp_sprite[inter.i_sp].index_x = inter.xtocheck / TILE_SIZE;
		inter.tmp_sprite[inter.i_sp].index_y = (inter.ytocheck) / TILE_SIZE;
		inter.tmp_sprite[inter.i_sp].hit_x =
		(inter.tmp_sprite[inter.i_sp].index_x * TILE_SIZE) + (TILE_SIZE / 2);
		inter.tmp_sprite[inter.i_sp].hit_y =
		(inter.tmp_sprite[inter.i_sp].index_y * TILE_SIZE) + (TILE_SIZE / 2);
		inter.tmp_sprite[inter.i_sp].distance = ft_distbpoints(player.x,
		player.y, inter.tmp_sprite[inter.i_sp].hit_x,
		inter.tmp_sprite[inter.i_sp].hit_y);
		inter.i_sp++;
	}
}

void	horinter2(int stripid)
{
	while (inter.nexthorztouchx >= 0
	&& inter.nexthorztouchx <= cols * TILE_SIZE
	&& inter.nexthorztouchy >= 0 && inter.nexthorztouchy <= rows * TILE_SIZE)
	{
		inter.xtocheck = inter.nexthorztouchx;
		inter.ytocheck = inter.nexthorztouchy +
		(inter.israyfacingup ? -1 : 0);
		horspinter();
		if (mapinter(inter.xtocheck, inter.ytocheck) == '1'
		|| mapinter(inter.xtocheck, inter.ytocheck) == '2')
		{
			inter.foundhorzwallhit = true;
			inter.horzwallhitx = inter.nexthorztouchx;
			inter.horzwallhity = inter.nexthorztouchy;
			inter.horzwallcontent =
				g_map[(int)floor(inter.ytocheck / TILE_SIZE)]
				[(int)floor(inter.xtocheck / TILE_SIZE)];
			break ;
		}
		else
		{
			inter.nexthorztouchx += inter.xstep;
			inter.nexthorztouchy += inter.ystep;
		}
	}
}

void	horinter(float rayangle, int stripid)
{
	inter.foundhorzwallhit = false;
	inter.horzwallhitx = 0;
	inter.horzwallhity = 0;
	inter.horzwallcontent = 0;
	inter.yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	inter.yintercept += inter.israyfacingdown ? TILE_SIZE : 0;
	inter.xintercept = player.x + (inter.yintercept - player.y) / tan(rayangle);
	inter.ystep = TILE_SIZE;
	inter.ystep *= inter.israyfacingup ? -1 : 1;
	inter.xstep = TILE_SIZE / tan(rayangle);
	inter.xstep *= (inter.israyfacingleft && inter.xstep > 0) ? -1 : 1;
	inter.xstep *= (inter.israyfacingright && inter.xstep < 0) ? -1 : 1;
	inter.nexthorztouchx = inter.xintercept;
	inter.nexthorztouchy = inter.yintercept;
	horinter2(stripid);
}
