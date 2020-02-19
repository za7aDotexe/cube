#include "cube.h"

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void castRay(float rayAngle, int stripId)
{
    rayAngle = normalizeAngle(rayAngle);

    int isRayFacingDown = rayAngle > 0 && rayAngle < PI;
    int isRayFacingUp = !isRayFacingDown;
    int isRayFacingRight = rayAngle < PI * 0.5 || rayAngle >  PI * 1.5;
    int isRayFacingLeft = !isRayFacingRight;


    float xintercept, yintercept;
    float xstep, ystep;

    ///////////////////////////////////////////
    // HORIZONTAL RAY-GRID INTERSECTION CODE
    ///////////////////////////////////////////
    int foundHorzWallHit = FALSE;
    float horzWallHitX = 0;
    float horzWallHitY = 0;
    int horzWallContent = 0;

    // Find the y-coordinate of the closest horizontal grid intersection
    yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
    yintercept += isRayFacingDown ? TILE_SIZE : 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = player.x + (yintercept - player.y) / tan(rayAngle);

    // Calculate the increment xstep and ystep
    ystep = TILE_SIZE;
    ystep *=  isRayFacingUp ? -1 : 1;

    xstep = TILE_SIZE / tan(rayAngle);
    xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
    xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

    float nextHorzTouchX = xintercept;
    float nextHorzTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextHorzTouchX >= 0 && nextHorzTouchX <= WINDOW_WIDTH && nextHorzTouchY >= 0 && nextHorzTouchY <= WINDOW_HEIGHT) 
    {
        float xTocheck = nextHorzTouchX;
        float yTocheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0 );    
        
        if (mapHasWallAt(xTocheck, yTocheck)) 
        {
            foundHorzWallHit = TRUE;
            horzWallHitX = nextHorzTouchX;
            horzWallHitY = nextHorzTouchY;
            horzWallContent = map[(int)floor(yTocheck / TILE_SIZE)][(int)floor(xTocheck / TILE_SIZE)];
            break;
        } 
        else {
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }


    ///////////////////////////////////////////
    // VERTICAL RAY-GRID INTERSECTION CODE
    ///////////////////////////////////////////
    int foundVertWallHit = FALSE;
    float vertWallHitX = 0;
    float vertWallHitY = 0;
    int vertWallContent = 0;

    // Find the x-coordinate of the closest vertical grid intersection
    xintercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
    xintercept += isRayFacingRight  ? TILE_SIZE : 0;

    // Find the y-coordinate of the closest vertical grid intersection
    yintercept = player.y + (xintercept - player.x) * tan(rayAngle);

    // Calculate the increment xstep and ystep
    xstep = TILE_SIZE;
    xstep *=  isRayFacingLeft ? -1 : 1;

    ystep = TILE_SIZE * tan(rayAngle);
    ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
    ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;

    float nextVertTouchX = xintercept;
    float nextVertTouchY = yintercept;

    // Increment xstep and ystep until we find a wall
    while (nextVertTouchX >= 0 && nextVertTouchX <= WINDOW_WIDTH && nextVertTouchY >= 0 && nextVertTouchY <= WINDOW_HEIGHT) 
    {
        float xTocheck = nextVertTouchX + (isRayFacingLeft  ? -1 : 0 );
        float yTocheck = nextVertTouchY ;    
        
        if (mapHasWallAt(xTocheck, yTocheck)) 
        {
            foundVertWallHit = TRUE;
            vertWallHitX = nextVertTouchX;
            vertWallHitY = nextVertTouchY;
            vertWallContent = map[(int)floor(yTocheck / TILE_SIZE)][(int)floor(xTocheck / TILE_SIZE)];
            break;
        } 
        else {
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }


    // calculate both vertical and horizontal hit distances and chose smallest  one !

    float horzHitDistance =  foundHorzWallHit
    ? ft_distbpoints(player.x, player.y, horzWallHitX, horzWallHitY) : INT_MAX;
    float vertHitDistance = foundVertWallHit 
    ? ft_distbpoints(player.x, player.y, vertWallHitX, vertWallHitY) : INT_MAX;

    if (vertHitDistance < horzHitDistance)
    {
        rays[stripId].distance = vertHitDistance;
        rays[stripId].wallHitX = vertWallHitX;
        rays[stripId].wallHitY  = vertWallHitY;
        rays[stripId].wallHitContent = vertWallContent;
        rays[stripId].wasHitVertical = TRUE;
    }
    else
    {
        rays[stripId].distance = horzHitDistance;
        rays[stripId].wallHitX = horzWallHitX;
        rays[stripId].wallHitY  = horzWallHitY;
        rays[stripId].wallHitContent = horzWallContent;
        rays[stripId].wasHitVertical = FALSE;
    }
    rays[stripId].rayAngle = rayAngle;
    rays[stripId].isRayFacingDown = isRayFacingDown;
    rays[stripId].isRayFacingUp = isRayFacingUp;
    rays[stripId].isRayFacingRight = isRayFacingRight;
    rays[stripId].isRayFacingLeft = isRayFacingLeft;
}


void    ft_castAllRays()
{
    float rayAngle;
    int stripId;

    rayAngle = player.rotationAngle - (FOV_ANGLE / 2.0); 
    stripId = 0;
    while (stripId < NUM_RAYS)
    {
        castRay(rayAngle, stripId);
        rayAngle += FOV_ANGLE / (double)NUM_RAYS;
        stripId++;
    }    
}

void    ft_renderRays()
{
    int i;

    i = 0;

    while (i++ < NUM_RAYS)
    {
        ft_draw_line(
            player.x * MINIMAP_SCALE_FACTOR, 
            player.y * MINIMAP_SCALE_FACTOR,
            rays[i - 1].wallHitX * MINIMAP_SCALE_FACTOR,
            rays[i  - 1].wallHitY * MINIMAP_SCALE_FACTOR 
        );
    }
    
}





void    ft_renderMap()
{
    int i;
	int j;
    float tileX;
    float tileY;

	i = 0;
	j = 0;

	tileX = 0;
	tileY = 0;
	while(j < MAP_NUM_ROWS)
	{
		i = 0;
		while(i < MAP_NUM_COLS)
		{
            tileY = j * TILE_SIZE;
            tileX = i * TILE_SIZE;
			if(map[j][i])
				ft_draw_square(
                    tileX * MINIMAP_SCALE_FACTOR, 
                    tileY * MINIMAP_SCALE_FACTOR, 
                    TILE_SIZE * MINIMAP_SCALE_FACTOR,
                    TILE_SIZE * MINIMAP_SCALE_FACTOR 
                );
            i++;
		}
        j++;
	}
}

int    mapHasWallAt(float x,float y)
{
    if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) 
        return TRUE;
    int mapGridIndexX = floor(x / TILE_SIZE);
    int mapGridIndexY = floor(y / TILE_SIZE);
    return map[mapGridIndexY][mapGridIndexX] != 0;
}