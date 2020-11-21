/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:54:01 by razaha            #+#    #+#             */
/*   Updated: 2020/11/19 18:34:37 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

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
