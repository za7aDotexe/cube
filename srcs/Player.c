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

void    ft_movePlayer()
{
    float moveStep;
    float newPlayerX = player.x;
    float newPlayerY = player.y;

    player.rotationAngle += player.turnDirection * player.turnSpeed * globspeed;
    
    if (player.walkUPDOWN)
    {
        moveStep = player.walkUPDOWN * player.walkSpeed * globspeed;
        newPlayerX += cos(player.rotationAngle) * moveStep;
        newPlayerY += sin(player.rotationAngle) * moveStep;
    }
    if (player.walkLEFTRIGHT)
    {
        moveStep = player.walkLEFTRIGHT * player.walkSpeed * globspeed;
        newPlayerX -= sin(player.rotationAngle) * moveStep;
        newPlayerY += cos(player.rotationAngle) * moveStep;
    }
    if (!mapHasWallAt(newPlayerX, newPlayerY))
    {
        player.x = newPlayerX;
        player.y = newPlayerY;
    }
}