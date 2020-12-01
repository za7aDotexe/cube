/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyshandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:05:59 by razaha            #+#    #+#             */
/*   Updated: 2020/12/01 16:58:21 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int		ft_destroywindown(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_presskey(int key)
{
	if (key == 53)
		ft_destroywindown();
	if (key == 0 || key == 1 || key == 2 || key == 13 || key == 123
			|| key == 124 || key == 116 || key == 125)
	{
		if (key == 13)
			g_player.walkupdown = +1;
		if (key == 1)
			g_player.walkupdown = -1;
		if (key == 2)
			g_player.walkleftright = +1;
		if (key == 0)
			g_player.walkleftright = -1;
		if (key == 124)
			g_player.turndirection = +2;
		if (key == 123)
			g_player.turndirection = -2;
	}
	return (0);
}

void	ft_reset(void)
{
	g_player.walkupdown = 0;
	g_player.walkupdown = 0;
	g_player.walkleftright = 0;
	g_player.walkleftright = 0;
	g_player.turndirection = 0;
	g_player.turndirection = 0;
}

int		ft_releasekey(int key)
{
	if (key == 259)
		ft_reset();
	if (key == 0 || key == 1 || key == 2 || key == 13 || key == 123
			|| key == 124)
	{
		if (key == 13)
			g_player.walkupdown = 0;
		if (key == 1)
			g_player.walkupdown = 0;
		if (key == 2)
			g_player.walkleftright = 0;
		if (key == 0)
			g_player.walkleftright = 0;
		if (key == 124)
			g_player.turndirection = 0;
		if (key == 123)
			g_player.turndirection = 0;
	}
	return (0);
}
