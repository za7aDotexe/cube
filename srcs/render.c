/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:38:24 by razaha            #+#    #+#             */
/*   Updated: 2020/11/24 19:29:44 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_render(void)
{
	mlx_destroy_image(g_mlx_ptr, g_threed_img);
	g_threed_img = mlx_new_image(g_mlx_ptr, g_window_width, g_window_height);
	ft_projection();
	ft_draw_sprites();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_threed_img, 0, 0);
}
