#include "cube.h"

void    ft_movePlayer()
{
    float moveStep;
    float newPlayerX = player.x;
    float newPlayerY = player.y;

    player.rotationAngle += player.turnDirection * player.turnSpeed * globspeed;
    
    if (player.walkLEFTRIGHT)
    {
        moveStep = player.walkLEFTRIGHT * player.walkSpeed * globspeed;
        newPlayerX -= sin(player.rotationAngle) * moveStep;
        newPlayerY += cos(player.rotationAngle) * moveStep;
    }
    
    
    if(player.walkUPDOWN)
    {
        moveStep = player.walkUPDOWN * player.walkSpeed * globspeed;
        newPlayerX += cos(player.rotationAngle) * moveStep;
        newPlayerY += sin(player.rotationAngle) * moveStep;
    }
    player.x = newPlayerX;
    player.y = newPlayerY;
}