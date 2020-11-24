/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:52:12 by razaha            #+#    #+#             */
/*   Updated: 2020/11/24 19:45:56 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	main(int argv, char **argc)
{
	int filedesc;

	if (argv < 2 || argv > 3 || open(argc[1], O_RDONLY) < 0)
		ft_puterror("(NO/INVALID) FIRST ARGUMENT or more than TWO ARGUMENT !");
	g_save = 0;
	if (argv == 3 && ft_is_save(argc[2]))
		g_save = 1;
	filedesc = open(argc[1], O_RDONLY);
	ft_read_cub_file(filedesc);
	close(filedesc);
	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr, g_window_width, g_window_height, "Cube 3D");
	g_threed_img = mlx_new_image(g_mlx_ptr, g_window_width, g_window_height);
	ft_initialize();
	mlx_hook(g_win_ptr, BUTTONPRESS, BUTTONPRESSMASK, ft_presskey, NULL);
	mlx_hook(g_win_ptr, KEYRELEASE, KEYRELEASEMASK, ft_releasekey, NULL);
	mlx_hook(g_win_ptr, DESTROYPRESS, DESTROYPRESSMASK, ft_destroywindown, NULL);
	mlx_loop_hook(g_mlx_ptr, ft_update, NULL);
	mlx_loop(g_mlx_ptr);
}
