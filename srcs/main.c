/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:52:12 by razaha            #+#    #+#             */
/*   Updated: 2020/11/08 19:10:23 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	main(int argv, char **argc)
{

	int filedesc = open("cube.cub", O_RDONLY);
	ft_read_cub_file(filedesc);
	close(filedesc);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cube 3D");
	twod_img = mlx_new_image(mlx_ptr, cols * TILE_SIZE, rows * TILE_SIZE);
	threed_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_setup();
	mlx_hook(win_ptr, buttonpress, buttonpressmask, ft_presskey, NULL);
	mlx_hook(win_ptr, keyrelease, keyreleasemask, ft_releasekey, NULL);
	mlx_hook(win_ptr, destroynotify, destroynotifymask, ft_destroywindown, NULL);
	mlx_loop_hook(mlx_ptr, ft_update, NULL);
	mlx_loop(mlx_ptr);
}
