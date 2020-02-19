#include "cube.h"

void ft_3Dprojection()
{

    int i;
    int j;


    i = 0;
    j = 0;

    while (i++ < NUM_RAYS)
    {
        float perpDistance = rays[i - 1].distance * cos(rays[i - 1].rayAngle - player.rotationAngle);
        float distanceProjPlane  = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
        float projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;

        int wallStripHeight = (int)projectedWallHeight;

        int wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

        int wallBottomPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);
        wallBottomPixel =  wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomPixel;

        j = 0;
        while (j++ < wallTopPixel)
        {
            ft_img_pixel_put_3d(threed_img, i - 1 , j - 1, 0x00ff00);
        }
        j = wallTopPixel;
        while (j++ < wallBottomPixel)
        {
            ft_img_pixel_put_3d(threed_img, i - 1, j - 1, rays[i - 1].wasHitVertical ? 0xffffff : 0xffcccc);
        }
        j = wallBottomPixel;
        while (j++ < WINDOW_HEIGHT)
        {
            ft_img_pixel_put_3d(threed_img, i - 1 , j - 1 , 0x0000ff );
        }
    }
}