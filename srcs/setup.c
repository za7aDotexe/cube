/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:41:46 by razaha            #+#    #+#             */
/*   Updated: 2020/02/20 22:18:54 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_setup(void)
{
	player.x = WINDOW_WIDTH / 2;
	player.y = WINDOW_HEIGHT / 2;
	player.width = 1;
	player.height = 1;
	player.turndirection = 0;
	player.walkupdown = 0;
	player.walkleftright = 0;
	player.rotationangle = PI / 2;
	player.walkspeed = 100;
	player.turnspeed = 30 * (PI / 180);
}
