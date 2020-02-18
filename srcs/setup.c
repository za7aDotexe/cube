#include "cube.h"

void    ft_setup()
{
    player.x = WINDOW_WIDTH / 2;
    player.y = WINDOW_HEIGHT / 2;
    player.width = 5;
    player.height = 5;
    player.turnDirection = 0;
    player.walkDirection = 0;
    player.rotationAngle = PI / 2;
    player.walkSpeed = 100;
    player.turnSpeed = 45 * (PI / 180);
}