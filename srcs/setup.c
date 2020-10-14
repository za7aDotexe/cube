/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:41:46 by razaha            #+#    #+#             */
/*   Updated: 2020/03/12 18:38:14 by razaha           ###   ########.fr       */
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
	g_sprites = NULL;
	textu.img = mlx_xpm_file_to_image(mlx_ptr, NTXT, &textu.width,
			&textu.height);
	textu.data = (int *)mlx_get_data_addr(textu.img, &textu.bpp,
			&textu.sizeline, &textu.endian);
	sprit.img = mlx_xpm_file_to_image(mlx_ptr, SPRIT, &sprit.width,
			&sprit.height);
	sprit.data = (int *)mlx_get_data_addr(sprit.img, &sprit.bpp,
			&sprit.sizeline, &sprit.endian);
}
