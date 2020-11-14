#include "../cube.h"

void ft_fill_vars(char *line,char **map)
{
	if(*line == 'R')
	{
		char **s1 = ft_split(line, ' ');
		WINDOW_WIDTH = ft_atoi(*(s1+1));
		WINDOW_HEIGHT = ft_atoi(*(s1+2));
	}
	if (*line == 'N' && *(line+1) == 'O')
	{
		line = line+2;
		while (*line == ' ' && *line != '\n')
			line++;
		NOTXT = line;
	}
	if (*line == 'S' && *(line+1) == 'O')
	{
		line = line+2;
		while (*line == ' ' && *line != '\n')
			line++;
		SOTXT = line;
	}
	if (*line == 'W' && *(line+1) == 'E')
	{
		line = line+2;
		while (*line == ' ' && *line != '\n')
			line++;
		WETXT = line;
	}
	if (*line == 'E' && *(line+1) == 'A')
	{
		line = line+2;
		while (*line == ' ' && *line != '\n')
			line++;
		EATXT = line;
	}
	if (*line == 'S')
	{
		line = line+2;
		while (*line == ' ' && *line != '\n')
			line++;
		SPRIT = line;
	}
	if (*line == 'F')
	{
        char **s1 = ft_split(line, ' ');
        char **s2 = ft_split(*(s1+1), ',');
        int r = ft_atoi(*(s2));
        int g = ft_atoi(*(s2+1));
        int b = ft_atoi(*(s2+2));
		FCOL = rgb_to_hex(r, g, b);
	}
    if (*line == 'C')
	{
        char **s1 = ft_split(line, ' ');
        char **s2 = ft_split(*(s1+1), ',');
        int r = ft_atoi(*(s2));
        int g = ft_atoi(*(s2+1));
        int b = ft_atoi(*(s2+2));
		CCOL = rgb_to_hex(r, g, b);
	}

	if(*line == '1' || *line == ' ' || *line == '0')
	{
		cols = ft_strlen(line) > cols ? ft_strlen(line) : cols;
		line = ft_strjoin(line, "\n");
		*map = ft_strjoin(*map, line);
		rows++;
	}
}

void ft_read_cub_file(int filedesc)
{
	char *line;
	char *map;
	rows = 0;
	cols = 0;

	map = ft_strdup("");

	while(get_next_line(filedesc , &line) != 0)
		ft_fill_vars(line, &map);
	ft_fill_vars(line, &map);
	ft_fill_map(map, rows, cols);
}
