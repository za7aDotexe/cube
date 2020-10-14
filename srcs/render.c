/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:38:24 by razaha            #+#    #+#             */
/*   Updated: 2020/03/10 21:30:53 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_render(void)
{
	mlx_destroy_image(mlx_ptr, twod_img);
	mlx_destroy_image(mlx_ptr, threed_img);
	twod_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH * MINIMAP_SCALE_FACTOR,
			WINDOW_HEIGHT * MINIMAP_SCALE_FACTOR);
	threed_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_rendermap();
	ft_renderplayer();
	ft_renderrays();
	ft_projection();
	ft_draw_sprites();
	mlx_put_image_to_window(mlx_ptr, win_ptr, threed_img, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, twod_img, 0, 0);
}
