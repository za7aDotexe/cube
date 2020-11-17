/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cube_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:01:53 by razaha            #+#    #+#             */
/*   Updated: 2020/11/17 13:47:05 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void ft_parse(char *line,char **map)
{
	if(*line == 'R')
		ft_fill_resolution(line);
	if ((*line == 'N' && *(line+1) == 'O') || (*line == 'S' && *(line+1) == 'O') || (*line == 'W' && *(line+1) == 'E') || (*line == 'E' && *(line+1) == 'A') || (*line == 'S' && *(line+1) == ' '))
		ft_textu(*line, *(line+1), line);
	if ((*line == 'F' || *line == 'C') && *(line+1) == ' ')
		ft_fill_floorciel_color(line);
	if (WINDOW_WIDTH && WINDOW_HEIGHT && NOTXT && SOTXT && WETXT && EATXT
	&& SPRIT && FCOL && CCOL)
	{
		if(*line == '1' || *line == ' ' || *line == '0')
		{
			cols = ft_strlen(line) > cols ? ft_strlen(line) : cols;
			line = ft_strjoin(line, "\n");
			*map = ft_strjoin(*map, line);
			rows++;
		}
	}
}

void ft_read_cub_file(int filedesc)
{
	char *line;
	char *map;
	rows = 0;
	cols = 0;

	map = ft_strdup("");
	while (get_next_line(filedesc , &line) != 0)
		ft_parse(line, &map);
	ft_parse(line, &map);
	ft_fill_map(map, rows, cols);
}
