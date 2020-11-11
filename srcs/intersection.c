/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:54:34 by razaha            #+#    #+#             */
/*   Updated: 2020/11/11 20:52:41 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	horinter2(int stripid)
{
	while (inter.nexthorztouchx >= 0 && inter.nexthorztouchx <= cols * TILE_SIZE &&
			inter.nexthorztouchy >= 0 && inter.nexthorztouchy <= rows * TILE_SIZE)
	{
		inter.xtocheck = inter.nexthorztouchx;
		inter.ytocheck = inter.nexthorztouchy + (inter.israyfacingup ? -1 : 0);
		if (mapinter(inter.xtocheck, inter.ytocheck) == '1' || mapinter(inter.xtocheck, inter.ytocheck) == '2')
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
		if (mapinter(inter.xtocheck, inter.ytocheck) == '3')
		{
			inter.foundhorspritehit = true;
			rays[stripid].foundhorspritehit = true;
			inter.horzspritehitx = inter.nexthorztouchx;
			inter.horzspritehity =inter.nexthorztouchy;
			ft_fill_sprite(stripid, (int)floor(inter.xtocheck / TILE_SIZE), (int)floor(inter.ytocheck / TILE_SIZE));
		}
	}
}

void	verinter2(int stripid)
{
	while (inter.nextverttouchx >= 0 && inter.nextverttouchx <= cols * TILE_SIZE &&
			inter.nextverttouchy >= 0 && inter.nextverttouchy <= rows * TILE_SIZE)
	{
		inter.xtocheck = inter.nextverttouchx +
			(inter.israyfacingleft ? -1 : 0);
		inter.ytocheck = inter.nextverttouchy;
		if (mapinter(inter.xtocheck, inter.ytocheck) == '1' || mapinter(inter.xtocheck, inter.ytocheck) == '2')
		{
			inter.foundvertwallhit = true;
			inter.vertwallhitx = inter.nextverttouchx;
			inter.vertwallhity = inter.nextverttouchy;
			inter.vertwallcontent =
				g_map[(int)floor(inter.ytocheck / TILE_SIZE)]
				[(int)floor(inter.xtocheck / TILE_SIZE)];
			break ;
		}
		else
		{
			inter.nextverttouchx += inter.xstep;
			inter.nextverttouchy += inter.ystep;
		}
		if (mapinter(inter.xtocheck, inter.ytocheck) == '3')
		{
			inter.foundverspritehit = true;
			rays[stripid].foundverspritehit = true;
			inter.verspritehitx = inter.nextverttouchx;
			inter.verspritehity = inter.nextverttouchy;
			ft_fill_sprite(stripid, (int)floor(inter.xtocheck / TILE_SIZE), (int)floor(inter.ytocheck / TILE_SIZE));
		}
	}
}

void	horinter(float rayangle, int stripid)
{
	inter.foundhorzwallhit = false;
	inter.foundhorspritehit = false;
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

void	verinter(float rayangle, int stripid)
{
	inter.foundvertwallhit = false;
	inter.foundverspritehit = false;
	inter.vertwallhitx = 0;
	inter.vertwallhity = 0;
	inter.vertwallcontent = 0;
	inter.xintercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
	inter.xintercept += inter.israyfacingright ? TILE_SIZE : 0;
	inter.yintercept = player.y + (inter.xintercept - player.x) * tan(rayangle);
	inter.xstep = TILE_SIZE;
	inter.xstep *= inter.israyfacingleft ? -1 : 1;
	inter.ystep = TILE_SIZE * tan(rayangle);
	inter.ystep *= (inter.israyfacingup && inter.ystep > 0) ? -1 : 1;
	inter.ystep *= (inter.israyfacingdown && inter.ystep < 0) ? -1 : 1;
	inter.nextverttouchx = inter.xintercept;
	inter.nextverttouchy = inter.yintercept;
	verinter2(stripid);
}