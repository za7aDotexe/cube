#include "cube.h"


void    ft_renderPlayer()
{
    ft_draw_square(
        player.x * MINIMAP_SCALE_FACTOR, 
        player.y * MINIMAP_SCALE_FACTOR, 
        player.width * MINIMAP_SCALE_FACTOR,
        player.height * MINIMAP_SCALE_FACTOR 
    );

    ft_draw_line(
        player.x * MINIMAP_SCALE_FACTOR ,
        player.y * MINIMAP_SCALE_FACTOR ,
        player.x * MINIMAP_SCALE_FACTOR + cos(player.rotationAngle) * 40 * MINIMAP_SCALE_FACTOR,
        player.y * MINIMAP_SCALE_FACTOR + sin(player.rotationAngle) * 40 * MINIMAP_SCALE_FACTOR 
    );
}