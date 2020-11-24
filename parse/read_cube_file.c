/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cube_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:01:53 by razaha            #+#    #+#             */
/*   Updated: 2020/11/24 19:29:14 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void	ft_parse2(char *line, char **map)
{
	char *temp;
	char *temp2;

	if (**map && *line == '\0')
		ft_puterror(".cub file must END with a map row !");
	if (*line == '1' || *line == ' ' || *line == '0')
	{
		g_cols = ft_strlen(line) > g_cols ? ft_strlen(line) : g_cols;
		temp2 = line;
		line = ft_strjoin(line, "\n");
		temp = *map;
		*map = ft_strjoin(*map, line);
		free(temp2);
		free(temp);
		g_rows++;
	}
	free(line);
}

void	ft_parse(char *line, char **map)
{
	char *temp;

	if (!g_window_width || !g_window_height || !g_notxt || !g_sotxt || !g_wetxt
	|| !g_eatxt || !g_sprit || !g_fcol || !g_ccol)
	{
		temp = line;
		while (*line == ' ' && *line)
			line++;
		if (*line == 'R')
			ft_fill_resolution(line);
		if ((*line == 'N' && *(line + 1) == 'O')
		|| (*line == 'S' && *(line + 1) == 'O')
		|| (*line == 'W' && *(line + 1) == 'E')
		|| (*line == 'E' && *(line + 1) == 'A')
		|| (*line == 'S' && *(line + 1) == ' '))
		{
			ft_textu(*line, *(line + 1), line);
		}
		if ((*line == 'F' || *line == 'C') && *(line + 1) == ' ')
			ft_fill_floorciel_color(line);
		free(temp);
		return ;
	}
	ft_parse2(line, map);
}

void	ft_read_cub_file(int filedesc)
{
	char *line;
	char *map;

	g_rows = 0;
	g_cols = 0;
	map = ft_strdup("");
	while (get_next_line(filedesc, &line) != 0)
		ft_parse(line, &map);
	ft_parse(line, &map);
	ft_fill_map(map, g_rows, g_cols);
	free(map);
	ft_check_map(g_rows, g_cols);
	ft_check_elements();
}
