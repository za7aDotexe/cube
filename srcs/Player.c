/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:54:01 by razaha            #+#    #+#             */
/*   Updated: 2020/02/20 20:04:38 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_renderplayer(void)
{
	ft_draw_square(
			player.x * MINIMAP_SCALE_FACTOR,
			player.y * MINIMAP_SCALE_FACTOR,
			player.width * MINIMAP_SCALE_FACTOR,
			player.height * MINIMAP_SCALE_FACTOR,
			twod_img);
	ft_draw_line(
			player.x * MINIMAP_SCALE_FACTOR,
			player.y * MINIMAP_SCALE_FACTOR,
			player.x * MINIMAP_SCALE_FACTOR + cos(player.rotationAngle) * 40
			* MINIMAP_SCALE_FACTOR,
			player.y * MINIMAP_SCALE_FACTOR + sin(player.rotationAngle) * 40
			* MINIMAP_SCALE_FACTOR,
			twod_img);
}

void	ft_moveplayer(void)
{
	float movestep;
	float newplayerx;
	float newplayery;

	newplayerx = player.x;
	newplayery = player.y;
	player.rotationAngle += player.turnDirection * player.turnSpeed * globspeed;
	if (player.walkUPDOWN)
	{
		moveStep = player.walkUPDOWN * player.walkSpeed * globspeed;
		newPlayerX += cos(player.rotationAngle) * moveStep;
		newPlayerY += sin(player.rotationAngle) * moveStep;
	}
	if (player.walkLEFTRIGHT)
	{
		movestep = player.walkLEFTRIGHT * player.walkSpeed * globspeed;
		newplayerx -= sin(player.rotationAngle) * moveStep;
		newPlayery += cos(player.rotationAngle) * moveStep;
	}
	if (!mapHasWallAt(newPlayerX, newPlayerY))
	{
		player.x = newPlayerX;
		player.y = newPlayerY;
	}
}
