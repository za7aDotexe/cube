#include "cube.h"

void    ft_render()
{
    mlx_destroy_image(mlx_ptr, img_ptr);
	img_ptr = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);

    ft_renderMap();
    ft_renderPlayer();
    // ft_renderRays();

    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}