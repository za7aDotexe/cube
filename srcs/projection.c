/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:44:33 by razaha            #+#    #+#             */
/*   Updated: 2020/11/29 19:14:27 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_right_texture(void)
{
	int text_id;

	if (!g_rays[g_projec.i - 1].washitverical)
	{
		if (g_rays[g_projec.i - 1].israyfacingdown)
			text_id = 0;
		if (g_rays[g_projec.i - 1].israyfacingup)
			text_id = 1;
	}
	if (g_rays[g_projec.i - 1].washitverical)
	{
		if (g_rays[g_projec.i - 1].israyfacingright)
			text_id = 2;
		if (g_rays[g_projec.i - 1].israyfacingleft)
			text_id = 3;
	}
	g_projec.distancefromtop = g_projec.j + (g_projec.wallstripheight / 2)
		- (g_window_height / 2);
	g_projec.texttureoffesty = g_projec.distancefromtop *
		((float)g_textures[text_id].height / g_projec.wallstripheight);
	if ((g_textures[text_id].width * g_projec.texttureoffesty
	+ g_projec.texttureoffestx * 2) < 4096)
		ft_img_pixel_put_3d(g_projec.i - 1,
		g_projec.j - 1, g_textures[text_id].data[g_textures[text_id].width
		* g_projec.texttureoffesty + g_projec.texttureoffestx * 2]);
}

void	ft_projection2(void)
{
	g_projec.j = 0;
	while (g_projec.j++ < g_projec.walltoppixel)
		ft_img_pixel_put_3d(g_projec.i - 1, g_projec.j - 1, g_ccol);
	if (g_rays[g_projec.i - 1].washitverical)
		g_projec.texttureoffestx =
		(int)g_rays[g_projec.i - 1].wallhity % TILE_SIZE;
	else
		g_projec.texttureoffestx =
		(int)g_rays[g_projec.i - 1].wallhitx % TILE_SIZE;
	g_projec.j = g_projec.walltoppixel;
	while (g_projec.j++ < g_projec.wallbottompixel)
	{
		ft_right_texture();
	}
	g_projec.j = g_projec.wallbottompixel;
	while (g_projec.j++ < g_window_height)
		ft_img_pixel_put_3d(g_projec.i - 1, g_projec.j - 1, g_fcol);
}

void	ft_projection(void)
{
	g_projec.i = 0;
	while (g_projec.i++ < NUM_RAYS)
	{
		g_projec.perpdistance = g_rays[g_projec.i - 1].walldistance
		* cos(g_rays[g_projec.i - 1].rayangle - g_player.rotationangle);
		g_projec.distanceprojplane = (g_window_width / 2)
		/ tan(FOV_ANGLE / 2);
		g_projec.projectedwallheight = (TILE_SIZE / g_projec.perpdistance)
		* g_projec.distanceprojplane;
		g_projec.wallstripheight = (int)g_projec.projectedwallheight;
		g_projec.walltoppixel = (g_window_height / 2)
		- (g_projec.wallstripheight / 2);
		g_projec.walltoppixel =
		g_projec.walltoppixel < 0 ? 0 : g_projec.walltoppixel;
		g_projec.wallbottompixel = (g_window_height / 2)
		+ (g_projec.wallstripheight / 2);
		g_projec.wallbottompixel = g_projec.wallbottompixel > g_window_height
		? g_window_height : g_projec.wallbottompixel;
		ft_projection2();
	}
}
