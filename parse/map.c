/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:56:08 by razaha            #+#    #+#             */
/*   Updated: 2020/11/17 17:03:51 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"


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
        }
    }
}