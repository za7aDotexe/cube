/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyshandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:05:59 by razaha            #+#    #+#             */
/*   Updated: 2020/11/03 18:38:09 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	ft_destroywindown(void)
{
	exit(0);
	return (0);
}

int	ft_presskey(int key)
{
	if (key == 53)
		ft_destroywindown();
	if (key == 0 || key == 1 || key == 2 || key == 13 || key == 123
			|| key == 124)
	{
		if (key == 13)
			player.walkupdown = +1;
		if (key == 1)
			player.walkupdown = -1;
		if (key == 2)
			player.walkleftright = +1;
		if (key == 0)
			player.walkleftright = -1;
		if (key == 124)
			player.turndirection = +2;
		if (key == 123)
			player.turndirection = -2;
	}
	return (0);
	
}

int	ft_releasekey(int key)
{
	if (key == 0 || key == 1 || key == 2 || key == 13 || key == 123
			|| key == 124)
	{
		if (key == 13)
			player.walkupdown = 0;
		if (key == 1)
			player.walkupdown = 0;
		if (key == 2)
			player.walkleftright = 0;
		if (key == 0)
			player.walkleftright = 0;
		if (key == 124)
			player.turndirection = 0;
		if (key == 123)
			player.turndirection = 0;
	}
	return (0);
}
