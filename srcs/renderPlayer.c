#include "cube.h"

void    ft_renderPlayer()
{ //  ft_draw_square(
//         player.x * MINIMAP_SCALE_FACTOR, 
//         player.y * MINIMAP_SCALE_FACTOR, 
//         player.width * MINIMAP_SCALE_FACTOR,
//         player.height * MINIMAP_SCALE_FACTOR 
//     );

    ft_draw_line(
        player.x,
        player.y,
        player.x + cos(player.rotationAngle) * 40,
        player.y + sin(player.rotationAngle) * 40
    );
}