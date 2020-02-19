#include "cube.h"

void    ft_render()
{
    mlx_destroy_image(mlx_ptr, twod_img);
    mlx_destroy_image(mlx_ptr, threed_img);
	twod_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH * MINIMAP_SCALE_FACTOR, WINDOW_HEIGHT * MINIMAP_SCALE_FACTOR );
    threed_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH , WINDOW_HEIGHT);

    ft_renderMap();
    ft_renderPlayer();
    ft_renderRays();
    ft_3Dprojection();


    mlx_put_image_to_window(mlx_ptr, win_ptr, threed_img, 0, 0);
    mlx_put_image_to_window(mlx_ptr, win_ptr, twod_img, 0, 0);
}