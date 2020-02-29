/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:41:46 by razaha            #+#    #+#             */
/*   Updated: 2020/02/29 22:02:55 by razaha           ###   ########.fr       */
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

	int bpp;
	int endian;

	textu.img = mlx_xpm_file_to_image(mlx_ptr, EAGLE, &textu.width , &textu.height);
	textu.data = (int *)mlx_get_data_addr(textu.img, &bpp, &textu.sizeline, &endian);
}
