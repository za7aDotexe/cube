/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:54:01 by razaha            #+#    #+#             */
/*   Updated: 2020/11/29 16:50:24 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_moveplayer(void)
{
	float movestep;
	float newplayerx;
	float newplayery;

	newplayerx = g_player.x;
	newplayery = g_player.y;
	g_player.rotationangle += g_player.turndirection * g_player.turnspeed
	* GLOBSPEED;
	if (g_player.walkupdown)
	{
		movestep = g_player.walkupdown * g_player.walkspeed * GLOBSPEED;
		newplayerx += cos(g_player.rotationangle) * movestep;
		newplayery += sin(g_player.rotationangle) * movestep;
	}
	if (g_player.walkleftright)
	{
		movestep = g_player.walkleftright * g_player.walkspeed * GLOBSPEED;
		newplayerx -= sin(g_player.rotationangle) * movestep;
		newplayery += cos(g_player.rotationangle) * movestep;
	}
	if (!maphaswallat(newplayerx, newplayery))
	{
		g_player.x = newplayerx;
		g_player.y = newplayery;
	}
}
