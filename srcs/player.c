/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:54:01 by razaha            #+#    #+#             */
/*   Updated: 2020/11/16 14:22:24 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_renderplayer(void)
{
	ft_draw_square(
			player.x * MMAP_SCE_FACTOR,
			player.y * MMAP_SCE_FACTOR,
			player.width * MMAP_SCE_FACTOR,
			player.height * MMAP_SCE_FACTOR);
	ft_draw_line(
			player.x * MMAP_SCE_FACTOR,
			player.y * MMAP_SCE_FACTOR,
			player.x * MMAP_SCE_FACTOR + cos(player.rotationangle) * 40
			* MMAP_SCE_FACTOR,
			player.y * MMAP_SCE_FACTOR + sin(player.rotationangle) * 40
			* MMAP_SCE_FACTOR);
}

void	ft_moveplayer(void)
{
	float movestep;
	float newplayerx;
	float newplayery;

	newplayerx = player.x;
	newplayery = player.y;
	player.rotationangle += player.turndirection * player.turnspeed * globspeed;
	if (player.walkupdown)
	{
		movestep = player.walkupdown * player.walkspeed * globspeed;
		newplayerx += cos(player.rotationangle) * movestep;
		newplayery += sin(player.rotationangle) * movestep;
	}
	if (player.walkleftright)
	{
		movestep = player.walkleftright * player.walkspeed * globspeed;
		newplayerx -= sin(player.rotationangle) * movestep;
		newplayery += cos(player.rotationangle) * movestep;
	}
	if (!maphaswallat(newplayerx, newplayery))
	{
		player.x = newplayerx;
		player.y = newplayery;
	}
}
