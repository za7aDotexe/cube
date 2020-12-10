/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cube_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:01:53 by razaha            #+#    #+#             */
/*   Updated: 2020/12/10 14:01:47 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void	ft_check_spaces(char *line)
{
	while (*line == ' ')
		if (*(++line) == '\0')
			ft_puterror("EMPTY LINE !");
}

void	ft_parse2(char *line, char **map)
{
	char *temp;
	char *temp2;

	if (**map && *line == '\0')
		ft_puterror(".cub file must END with a map row !");
	if (*line == '1' || *line == ' ' || *line == '0')
	{
		ft_check_spaces(line);
		g_cols = ft_strlen(line) > g_cols ? ft_strlen(line) : g_cols;
		temp2 = line;
		line = ft_strjoin(line, "\n");
		temp = *map;
		*map = ft_strjoin(*map, line);
		free(temp2);
		free(temp);
		g_rows++;
	}
	else if (*line != '\0')
		ft_puterror("INVALID LINE !");
	free(line);
}

void	ft_parse(char *line, char **map)
{
	char *temp;

	if (!g_window_width || !g_window_height || !g_notxt || !g_sotxt || !g_wetxt
	|| !g_eatxt || !g_sprit || g_fcol < 0 || g_ccol < 0)
	{
		temp = line;
		ft_check_spaces(line);
		if (*line == 'R' && *(line + 1) == ' ')
			ft_fill_resolution(line);
		else if ((*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		|| (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		|| (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		|| (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		|| (*line == 'S' && *(line + 1) == ' '))
			ft_textu(*line, *(line + 1), line);
		else if ((*line == 'F' || *line == 'C') && *(line + 1) == ' ')
			ft_fill_floorciel_color(line);
		else if (*line != '\0')
			ft_puterror("INVALID LINE !");
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
	g_fcol = -1;
	g_ccol = -1;
	g_num_sp = 0;
	map = ft_strdup("");
	while (get_next_line(filedesc, &line) != 0)
		ft_parse(line, &map);
	ft_parse(line, &map);
	ft_fill_map(map);
	free(map);
	ft_check_elements();
	ft_check_map();
}
