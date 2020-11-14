/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:41:46 by razaha            #+#    #+#             */
/*   Updated: 2020/11/14 19:55:08 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_setup(void)
{
	player.x = WINDOW_WIDTH;
	player.y = WINDOW_HEIGHT;
	player.width = 1;
	player.height = 1;
	player.turndirection = 0;
	player.walkupdown = 0;
	player.walkleftright = 0;
	player.rotationangle = PI /2;
	player.walkspeed = 100;
	player.turnspeed = 30 * (PI / 180);
	rays = malloc(WINDOW_WIDTH * sizeof(struct Ray));
	g_sprites = NULL;
	g_textures[0].img = mlx_xpm_file_to_image(mlx_ptr, NOTXT, &g_textures[0].width,
			&g_textures[0].height);
	g_textures[0].data = (int *)mlx_get_data_addr(g_textures[0].img, &g_textures[0].bpp,
			&g_textures[0].sizeline, &g_textures[0].endian);
	g_textures[1].img = mlx_xpm_file_to_image(mlx_ptr, SOTXT, &g_textures[1].width,
			&g_textures[1].height);
	g_textures[1].data = (int *)mlx_get_data_addr(g_textures[1].img, &g_textures[1].bpp,
			&g_textures[1].sizeline, &g_textures[1].endian);
	g_textures[2].img = mlx_xpm_file_to_image(mlx_ptr, WETXT, &g_textures[2].width,
			&g_textures[2].height);
	g_textures[2].data = (int *)mlx_get_data_addr(g_textures[2].img, &g_textures[2].bpp,
			&g_textures[2].sizeline, &g_textures[2].endian);
	g_textures[3].img = mlx_xpm_file_to_image(mlx_ptr, EATXT, &g_textures[3].width,
			&g_textures[3].height);
	g_textures[3].data = (int *)mlx_get_data_addr(g_textures[3].img, &g_textures[3].bpp,
			&g_textures[3].sizeline, &g_textures[3].endian);
	g_textures[4].img = mlx_xpm_file_to_image(mlx_ptr, SPRIT, &g_textures[4].width,
			&g_textures[4].height);
	g_textures[4].data = (int *)mlx_get_data_addr(g_textures[4].img, &g_textures[4].bpp,
			&g_textures[4].sizeline, &g_textures[4].endian);
}
