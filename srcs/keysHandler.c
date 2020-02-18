#include "cube.h"


int ft_presskey(int key)
{
    if (key == 53)
		exit(0);
	
	if(key == 0 || key == 1 || key == 2 || key == 13 || key == 123 || key == 124)
	{
    	if(key == 13)
			player.walkUPDOWN = +1;
		if(key == 1)
			player.walkUPDOWN = -1;
		if(key == 2)
			player.walkLEFTRIGHT = +1;
		if(key == 0)
			player.walkLEFTRIGHT = -1;
		if(key == 124)
			player.turnDirection = +1;
		if(key == 123) 
			player.turnDirection = -1;
	}
    return (0);
}

int ft_releasekey(int key)
{
	if(key == 0 || key == 1 || key == 2 || key == 13 || key == 123 || key == 124)
	{
    	if(key == 13)
			player.walkUPDOWN = 0;
		if(key == 1)
			player.walkUPDOWN = 0;
		if(key == 2)
			player.walkLEFTRIGHT = 0;
		if(key == 0)
			player.walkLEFTRIGHT = 0;
		if(key == 124)
			player.turnDirection = 0;
		if(key == 123) 
			player.turnDirection = 0;
	}
    return (0);
}

