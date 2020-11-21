/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:52:12 by razaha            #+#    #+#             */
/*   Updated: 2020/11/21 20:30:03 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	ft_is_save()
{
	// if(ft_strlen(save) != 6 || ft_strncmp("--save", save, 6))
	// // 	ft_puterror("INVALID second argument !");
	printf("tchaaak ");
	ft_bitmap(0,0,0,0);
	exit(EXIT_SUCCESS);
}


int	main(int argv, char **argc)
{
	int filedesc;
	
	if (argv < 2 && argv > 3)
		ft_puterror("There is NO FIRST ARGUMENT or more than TWO ARGUMENT !");
	filedesc = open(argc[1], O_RDONLY);
	ft_read_cub_file(filedesc);
	close(filedesc);
	ft_check();
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cube 3D");
	threed_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_initialize();
	g_save = 0;
	if(argv == 3)
		g_save = 1;
	// 	ft_is_save(argc[2]);
	mlx_hook(win_ptr, buttonpress, buttonpressmask, ft_presskey, NULL);
	mlx_hook(win_ptr, keyrelease, keyreleasemask, ft_releasekey, NULL);
	mlx_hook(win_ptr, destroypress, destroypressmask, ft_destroywindown, NULL);
	mlx_loop_hook(mlx_ptr, ft_update, NULL);
	mlx_loop(mlx_ptr);
}
