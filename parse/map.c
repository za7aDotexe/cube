/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:56:08 by razaha            #+#    #+#             */
/*   Updated: 2020/11/18 20:41:25 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void ft_setup_player(char dir, int x, int y)
{
    if (dir == 'N')
        player.rotationangle = -PI / 2;
    if (dir == 'S')
        player.rotationangle = PI/2;
    if (dir == 'E')
        player.rotationangle = 0;
    if (dir == 'W')
         player.rotationangle = PI ;
	player.x = x * TILE_SIZE + TILE_SIZE / 2; 
	player.y = y * TILE_SIZE + TILE_SIZE / 2;
	player.player += 1;
}

void    ft_fill_map(char *ptr, int rows, int cols)
{
    char **line = ft_split(ptr, '\n');
    int i = 0;
    int j = 0;
    int var;
    
    g_map = malloc(sizeof(char *) * rows);
    while(i++ < rows)
    {
        g_map[i-1] = malloc(sizeof(char) * cols);
        j = 0;
        var = ft_strlen(line[i-1]);
        while (j++ < cols)
        {
            if(j-1 >= var)
                g_map[i-1][j-1] = ' ';
            else
                g_map[i-1][j-1] = line[i-1][j-1];
            if(g_map[i-1][j-1] == 'N' || g_map[i-1][j-1] == 'S' || g_map[i-1][j-1] == 'W' || g_map[i-1][j-1] == 'E')
                ft_setup_player(g_map[i-1][j-1], j-1, i-1);
        }
    }
    
}