#include "cube.h"

int     ft_update()
{
    ft_movePlayer();
    ft_castAllRays();

    ft_render();
    return (0);
}