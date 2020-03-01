/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:54:01 by razaha            #+#    #+#             */
/*   Updated: 2020/03/01 17:10:47 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_renderplayer(void)
{
	ft_draw_square(
			player.x * MINIMAP_SCALE_FACTOR,
			player.y * MINIMAP_SCALE_FACTOR,
			player.width * MINIMAP_SCALE_FACTOR,
			player.height * MINIMAP_SCALE_FACTOR);
	ft_draw_line(
			player.x * MINIMAP_SCALE_FACTOR,
			player.y * MINIMAP_SCALE_FACTOR,
			player.x * MINIMAP_SCALE_FACTOR + cos(player.rotationangle) * 40
			* MINIMAP_SCALE_FACTOR,
			player.y * MINIMAP_SCALE_FACTOR + sin(player.rotationangle) * 40
			* MINIMAP_SCALE_FACTOR);
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
