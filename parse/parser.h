#ifndef PARSER_H_
# define PARSER_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char **g_map;
int num_sp;


int		get_next_line(int fd, char **line);
void    ft_fill_map(char *ptr, int rows, int cols);
void ft_check_map(int rows, int cols);

#endif

