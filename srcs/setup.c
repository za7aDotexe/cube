/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:41:46 by razaha            #+#    #+#             */
/*   Updated: 2020/11/03 20:57:35 by razaha           ###   ########.fr       */
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
	g_textures[0].img = mlx_xpm_file_to_image(mlx_ptr, NOTXT, &g_textures[0].width,
			&g_textures[0].height);
	g_textures[0].data = (int *)mlx_get_data_addr(g_textures[0].img, &g_textures[0].bpp,
			&g_textures[0].sizeline, &g_textures[0].endian);
	g_textures[4].img = mlx_xpm_file_to_image(mlx_ptr, SPRIT, &g_textures[0].width,
			&g_textures[4].height);
	g_textures[4].data = (int *)mlx_get_data_addr(g_textures[4].img, &g_textures[4].bpp,
			&g_textures[4].sizeline, &g_textures[4].endian);
}
