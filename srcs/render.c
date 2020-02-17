#include "cube.h"

int    ft_render()
{
    mlx_destroy_image(mlx_ptr, img_ptr);
	img_ptr = mlx_new_image(mlx_ptr, screenWidth, screenHeight);

    //render all game objects for the current frame
    ft_draw_square(x++, y++, 20, 20);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

    return (0);
}