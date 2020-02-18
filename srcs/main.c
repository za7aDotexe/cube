#include "cube.h"






int     main()
{
    mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cube 3D");
	img_ptr = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);

    ft_setup();

	mlx_hook(win_ptr, ButtonPress, ButtonPressMask, ft_processinput, NULL);
    mlx_loop_hook (mlx_ptr, ft_update, NULL);

    mlx_loop(mlx_ptr);
}