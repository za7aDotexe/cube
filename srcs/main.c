#include "cube.h"

int     main()
{
    mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Cube 3D");
	img_ptr = mlx_new_image(mlx_ptr, screenWidth, screenHeight);

	mlx_hook(win_ptr, ButtonPress, ButtonPressMask, ft_processinput, NULL);
    mlx_loop_hook (mlx_ptr, ft_render, NULL);

    mlx_loop(mlx_ptr);
}