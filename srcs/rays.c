/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:17:40 by razaha            #+#    #+#             */
/*   Updated: 2020/02/20 23:02:46 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void	castray(float rayangle, int stripid)
{
	int		israyfacingdown;
	int		israyfacingup;
	int		israyfacingright;
	int		israyfacingleft;
	float	verthitdistance;
	float 	horzhitdistance;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		foundhorzwallhit;
	float	horzwallhitx;
	float	horzwallhity;
	int		horzwallcontent;
	int		foundvertwallhit;
	float	vertwallhitx;
	float	vertwallhity;
	int		vertwallcontent;
	float	nexthorztouchx;
	float	nexthorztouchy;
	float	nextverttouchx;
	float	nextverttouchy;
	float	xtocheck;
	float	ytocheck;

	rayangle = normalizeangle(rayangle);
	israyfacingdown = rayangle > 0 && rayangle < PI;
	israyfacingup = !israyfacingdown;
	israyfacingright = rayangle < PI * 0.5 || rayangle > PI * 1.5;
	israyfacingleft = !israyfacingright;
	foundhorzwallhit = false;
	horzwallhitx = 0;
	horzwallhity = 0;
	horzwallcontent = 0;
	yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	yintercept += israyfacingdown ? TILE_SIZE : 0;
	xintercept = player.x + (yintercept - player.y) / tan(rayangle);
	ystep = TILE_SIZE;
	ystep *= israyfacingup ? -1 : 1;
	xstep = TILE_SIZE / tan(rayangle);
	xstep *= (israyfacingleft && xstep > 0) ? -1 : 1;
	xstep *= (israyfacingright && xstep < 0) ? -1 : 1;
	nexthorztouchx = xintercept;
	nexthorztouchy = yintercept;
	while (nexthorztouchx >= 0 && nexthorztouchx <= WINDOW_WIDTH &&
			nexthorztouchy >= 0 && nexthorztouchy <= WINDOW_HEIGHT)
	{
		xtocheck = nexthorztouchx;
		ytocheck = nexthorztouchy + (israyfacingup ? -1 : 0);
		if (maphaswallat(xtocheck, ytocheck))
		{
			foundhorzwallhit = true;
			horzwallhitx = nexthorztouchx;
			horzwallhity = nexthorztouchy;
			horzwallcontent =
				map[(int)floor(ytocheck / TILE_SIZE)]
				[(int)floor(xtocheck / TILE_SIZE)];
			break ;
		}
		else
		{
			nexthorztouchx += xstep;
			nexthorztouchy += ystep;
		}
	}
	foundvertwallhit = false;
	vertwallhitx = 0;
	vertwallhity = 0;
	vertwallcontent = 0;
	xintercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
	xintercept += israyfacingright ? TILE_SIZE : 0;
	yintercept = player.y + (xintercept - player.x) * tan(rayangle);
	xstep = TILE_SIZE;
	xstep *= israyfacingleft ? -1 : 1;
	ystep = TILE_SIZE * tan(rayangle);
	ystep *= (israyfacingup && ystep > 0) ? -1 : 1;
	ystep *= (israyfacingdown && ystep < 0) ? -1 : 1;
	nextverttouchx = xintercept;
	nextverttouchy = yintercept;
	while (nextverttouchx >= 0 && nextverttouchx <= WINDOW_WIDTH &&
			nextverttouchy >= 0 && nextverttouchy <= WINDOW_HEIGHT)
	{
		xtocheck = nextverttouchx + (israyfacingleft ? -1 : 0);
		ytocheck = nextverttouchy;
		if (maphaswallat(xtocheck, ytocheck))
		{
			foundvertwallhit = true;
			vertwallhitx = nextverttouchx;
			vertwallhity = nextverttouchy;
			vertwallcontent =
				map[(int)floor(ytocheck / TILE_SIZE)]
				[(int)floor(xtocheck / TILE_SIZE)];
			break ;
		}
		else
		{
			nextverttouchx += xstep;
			nextverttouchy += ystep;
		}
	}
	horzhitdistance = foundhorzwallhit ?
		ft_distbpoints(player.x, player.y, horzwallhitx, horzwallhity)
		: INT_MAX;
	verthitdistance = foundvertwallhit ?
		ft_distbpoints(player.x, player.y, vertwallhitx, vertwallhity)
		: INT_MAX;
	if (verthitdistance < horzhitdistance)
	{
		rays[stripid].distance = verthitdistance;
		rays[stripid].wallhitx = vertwallhitx;
		rays[stripid].wallhity = vertwallhity;
		rays[stripid].wallhitcontent = vertwallcontent;
		rays[stripid].washitvertical = true;
	}
	else
	{
		rays[stripid].distance = horzhitdistance;
		rays[stripid].wallhitx = horzwallhitx;
		rays[stripid].wallhity = horzwallhity;
		rays[stripid].wallhitcontent = horzwallcontent;
		rays[stripid].washitvertical = false;
	}
	rays[stripid].rayangle = rayangle;
	rays[stripid].israyfacingdown = israyfacingdown;
	rays[stripid].israyfacingup = israyfacingup;
	rays[stripid].israyfacingright = israyfacingright;
	rays[stripid].israyfacingleft = israyfacingleft;
}

void	ft_castallrays(void)
{
	int		stripid;
	float	rayangle;

	rayangle = player.rotationangle - (FOV_ANGLE / 2.0);
	stripid = 0;
	while (stripid < NUM_RAYS)
	{
		castray(rayangle, stripid);
		rayangle += FOV_ANGLE / (double)NUM_RAYS;
		stripid++;
	}
}

void	ft_renderrays(void)
{
	int i;

	i = 0;
	while (i++ < NUM_RAYS)
	{
		ft_draw_line(
				player.x * MINIMAP_SCALE_FACTOR,
				player.y * MINIMAP_SCALE_FACTOR,
				rays[i - 1].wallhitx * MINIMAP_SCALE_FACTOR,
				rays[i - 1].wallhity * MINIMAP_SCALE_FACTOR,
				twod_img);
	}
}

void	ft_rendermap(void)
{
	int		i;
	int		j;
	float	tilex;
	float	tiley;

	i = 0;
	j = 0;
	tilex = 0;
	tiley = 0;
	while (j++ < MAP_NUM_ROWS)
	{
		i = 0;
		while (i++ < MAP_NUM_COLS)
		{
			tiley = (j - 1) * TILE_SIZE;
			tilex = (i - 1) * TILE_SIZE;
			if (map[j - 1][i - 1])
				ft_draw_square(
						tilex * MINIMAP_SCALE_FACTOR,
						tiley * MINIMAP_SCALE_FACTOR,
						TILE_SIZE * MINIMAP_SCALE_FACTOR,
						TILE_SIZE * MINIMAP_SCALE_FACTOR,
						twod_img);
		}
	}
}

int		maphaswallat(float x, float y)
{
	int mapgridindexx;
	int mapgridindexy;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return (true);
	mapgridindexx = floor(x / TILE_SIZE);
	mapgridindexy = floor(y / TILE_SIZE);
	return (map[mapgridindexy][mapgridindexx] != 0);
}
