/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:52:12 by razaha            #+#    #+#             */
/*   Updated: 2020/03/13 20:43:18 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void ft_fill_vars(char *line)
{
	if (*line == 'R')
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
		NTXT = line;
	}
	if (*line == 'S' && *(line+1) == 'O')
	{
		line = line+2;
		while (*line == ' ' && *line != '\n')
			line++;
		STXT = line;
	}
	if (*line == 'W' && *(line+1) == 'E')
	{
		line = line+2;
		while (*line == ' ' && *line != '\n')
			line++;
		WTXT = line;
	}
	if (*line == 'E' && *(line+1) == 'A')
	{
		line = line+2;
		while (*line == ' ' && *line != '\n')
			line++;
		ETXT = line+3;
	}
	if (*line == 'S')
	{
		line = line+2;
		while (*line == ' ' && *line != '\n')
			line++;
		SPRIT = line;
	}
	// 	if (*line == 'F')
	// {
	// 	line = line+2;
	// 	while (*line == ' ' && *line != '\n')
	// 		line++;
	// 	FCOL = line;
	// }
	// 	if (*line == 'C')
	// {
	// 	line = line+2;
	// 	while (*line == ' ' && *line != '\n')
	// 		line++;
	// 	CCOL = line;
	// }
	if(*line == '1' || *line ==  ' ')
	{
		cols = cols < ft_strlen(line) ? ft_strlen(line) : cols;
		rows++;
	}
}

void ft_read_cub_file(int filedesc)
{
	char *line;
	cols = 0;
	rows = 0;
	
	while(get_next_line(filedesc , &line) != 0)
		ft_fill_vars(line);
	printf("%d %d\n", cols , rows);
}

int	main(int argv, char **argc)
{

	int filedesc = open("cube.cub", O_RDONLY);
	ft_read_cub_file(filedesc);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cube 3D");
	twod_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	threed_img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_setup();
	mlx_hook(win_ptr, buttonpress, buttonpressmask, ft_presskey, NULL);
	mlx_hook(win_ptr, keyrelease, keyreleasemask, ft_releasekey, NULL);
	mlx_loop_hook(mlx_ptr, ft_update, NULL);
	mlx_loop(mlx_ptr);
}
