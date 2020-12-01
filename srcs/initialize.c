/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:41:46 by razaha            #+#    #+#             */
/*   Updated: 2020/12/01 14:09:01 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_initialize2(void)
{
	g_textures[0].img = mlx_xpm_file_to_image(g_mlx_ptr, g_notxt,
	&g_textures[0].width, &g_textures[0].height);
	g_textures[0].data = (int *)mlx_get_data_addr(g_textures[0].img,
	&g_textures[0].bpp, &g_textures[0].sizeline, &g_textures[0].endian);
	g_textures[1].img = mlx_xpm_file_to_image(g_mlx_ptr, g_sotxt,
	&g_textures[1].width, &g_textures[1].height);
	g_textures[1].data = (int *)mlx_get_data_addr(g_textures[1].img,
	&g_textures[1].bpp, &g_textures[1].sizeline, &g_textures[1].endian);
	g_textures[2].img = mlx_xpm_file_to_image(g_mlx_ptr, g_wetxt,
	&g_textures[2].width, &g_textures[2].height);
	g_textures[2].data = (int *)mlx_get_data_addr(g_textures[2].img,
	&g_textures[2].bpp, &g_textures[2].sizeline, &g_textures[2].endian);
	g_textures[3].img = mlx_xpm_file_to_image(g_mlx_ptr, g_eatxt,
	&g_textures[3].width, &g_textures[3].height);
	g_textures[3].data = (int *)mlx_get_data_addr(g_textures[3].img,
	&g_textures[3].bpp, &g_textures[3].sizeline, &g_textures[3].endian);
	g_textures[4].img = mlx_xpm_file_to_image(g_mlx_ptr, g_sprit,
	&g_textures[4].width, &g_textures[4].height);
	g_textures[4].data = (int *)mlx_get_data_addr(g_textures[4].img,
	&g_textures[4].bpp, &g_textures[4].sizeline, &g_textures[4].endian);
}

void	ft_initialize(void)
{
	int size;

	size = sizeof(struct s_ray);
	g_player.turndirection = 0;
	g_player.walkupdown = 0;
	g_player.walkleftright = 0;
	g_player.walkspeed = 150;
	g_player.turnspeed = 30 * (PI / 180);
	g_rays = malloc(g_window_width * size);
	g_sprites = NULL;
	ft_initialize2();
}
