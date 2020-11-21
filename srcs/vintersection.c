/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vintersection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:54:34 by razaha            #+#    #+#             */
/*   Updated: 2020/11/19 17:34:09 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	verspinter(void)
{
	if (mapinter(inter.xtocheck, inter.ytocheck) == '2')
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

void	verinter2(int stripid)
{
	while (inter.nextverttouchx >= 0
	&& inter.nextverttouchx <= cols * TILE_SIZE
	&& inter.nextverttouchy >= 0 && inter.nextverttouchy <= rows * TILE_SIZE)
	{
		inter.xtocheck = inter.nextverttouchx +
		(inter.israyfacingleft ? -1 : 0);
		inter.ytocheck = inter.nextverttouchy;
		verspinter();
		if (mapinter(inter.xtocheck, inter.ytocheck) == '1')
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
	}
}

void	verinter(float rayangle, int stripid)
{
	inter.foundvertwallhit = false;
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
