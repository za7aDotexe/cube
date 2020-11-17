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
void    ft_check_map(int rows, int cols);
void	ft_fill_floorciel_color(char *line);
void    ft_fill_resolution(char *line);
void	ft_textu(char c, char c2, char *line);
void     ft_check();
void    ft_check_elements();
int	    ft_puterror(char *error);


#endif

