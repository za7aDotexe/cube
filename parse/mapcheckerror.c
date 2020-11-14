#include "parser.h"

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
    int i = 0;
    int j = 0;
    while (i++ < rows)
    {
        j = 0;
        while (j++ < cols)
        {
            if (i-1 == 0 || j-1 == 0 || i-1 == rows-1 || j-1 == cols-1)
                if(g_map[i-1][j-1] == '0')
                {
                    // printf("map borders m7lol at i: %d  j: %d\n", i-1, j-1);
                    exit(EXIT_FAILURE);
                }
            if(g_map[i-1][j-1] == ' ')
                if(!ft_check_arr_space(i-1, j-1,rows,cols))
                {
                    // printf("map m7looool\n");
                    exit(EXIT_FAILURE);
                }
        }
        
    }
    
}