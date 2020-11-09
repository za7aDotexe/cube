#include "parser.h"

void    ft_fill_map(char *ptr, int rows, int cols)
{
    char **line = ft_split(ptr, '\n');
    int i = 0;
    int j = 0;
    int var;
    
    g_map = malloc(sizeof(char *) * rows);
    while(i++ < rows)
        g_map[i-1] = malloc(sizeof(char) * cols);
    i = 0;
    while(i++ < rows)
    {
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
   ft_check_map(rows, cols);
}