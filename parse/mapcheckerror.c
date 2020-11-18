/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:56:13 by razaha            #+#    #+#             */
/*   Updated: 2020/11/18 20:41:32 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"



int ft_check_arr_space(int i, int j, int rows, int cols)
{
    if(i > 0 && g_map[i-1][j] != ' ' && g_map[i-1][j] != '1')
        return(0);
    if(i < rows - 1 && g_map[i+1][j] != ' ' && g_map[i+1][j] != '1')
        return(0);
    if(j > 0 && g_map[i][j-1] != ' ' && g_map[i][j-1] != '1')
        return(0);
    if(j < cols - 1 && g_map[i][j+1] != ' ' && g_map[i][j+1] != '1')
        return(0);
    return (1);
}

void ft_check_map(int rows, int cols)
{
    int i;
    int j;

    i = 0;
    j = 0;
    num_sp = 0;
    while (i++ < rows)
    {
        j = 0;
        while (j++ < cols)
        {
            if (i-1 == 0 || j-1 == 0 || i-1 == rows-1 || j-1 == cols-1)
                if(g_map[i-1][j-1] == '0')
                    ft_puterror("One of the map borders is open !");
            if(g_map[i-1][j-1] == ' ')
                if(!ft_check_arr_space(i-1, j-1,rows,cols))
                    ft_puterror("Map is vulnerable !");
            g_map[i-1][j-1] == '3' ? num_sp++ :  num_sp ;
        }
    }
}