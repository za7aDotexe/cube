#include "parser.h"

// void ft_read_cub_file(int filedesc)
// {
// 	char *line;
//     char *ptr;
//     char *save;
//     int rows = 1;
//     int cols = 0;

//     ptr = ft_strdup("");
// 	while(get_next_line(filedesc , &line) != 0)
//     {
//         if(*line == '1' || *line == ' ' || *line == '0')
//         {
//             cols = ft_strlen(line) > cols ? ft_strlen(line) : cols;
//             save = line;
//             line = ft_strjoin(line, "\n");
//             free(save);
//             save = ptr;
//             ptr = ft_strjoin(ptr, line);
//             free(save);
//             rows++;
//         }
//         free(line);
//     }
//     ptr = ft_strjoin(ptr, line);
//     ft_fill_map(ptr, rows, cols);
// }

// int main(void)
// {
// 	int filedesc = open("cube.cub", O_RDONLY);
// 	ft_read_cub_file(filedesc);
// 	close(filedesc);
//     return (0);

// }