/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:52:12 by razaha            #+#    #+#             */
/*   Updated: 2020/02/20 19:53:22 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(void)
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cube 3D");
	twod_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	threed_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_setup();
	mlx_hook(win_ptr, ButtonPress, ButtonPressMask, ft_presskey, NULL);
	mlx_hook(win_ptr, KeyRelease, KeyReleaseMask, ft_releasekey, NULL);
	mlx_loop_hook(mlx_ptr, ft_update, NULL);
	mlx_loop(mlx_ptr);
}
