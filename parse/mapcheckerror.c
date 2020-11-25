/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:56:13 by razaha            #+#    #+#             */
/*   Updated: 2020/11/25 19:14:22 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

int		ft_check_arr_space(int i, int j, int g_rows, int g_cols)
{
	if (i > 0 && g_map[i - 1][j] != ' ' && g_map[i - 1][j] != '1')
		return (0);
	if (i < g_rows - 1 && g_map[i + 1][j] != ' ' && g_map[i + 1][j] != '1')
		return (0);
	if (j > 0 && g_map[i][j - 1] != ' ' && g_map[i][j - 1] != '1')
		return (0);
	if (j < g_cols - 1 && g_map[i][j + 1] != ' ' && g_map[i][j + 1] != '1')
		return (0);
	return (1);
}

void	ft_check_map(int g_rows, int g_cols)
{
	int i;
	int j;

	i = 0;
	num_sp = 0;
	while (i++ < g_rows)
	{
		j = 0;
		while (j++ < g_cols)
		{
			if (g_map[i - 1][j - 1] != '0' && g_map[i - 1][j - 1] != '1'
			&& g_map[i - 1][j - 1] != '2' && g_map[i - 1][j - 1] != ' '
			&& g_map[i - 1][j - 1] != 'N' && g_map[i - 1][j - 1] != 'S'
			&& g_map[i - 1][j - 1] != 'W' && g_map[i - 1][j - 1] != 'E')
				ft_puterror("INVALID map character !");
			if (i - 1 == 0 || j - 1 == 0 || i - 1 == g_rows - 1
			|| j - 1 == g_cols - 1)
				if (g_map[i - 1][j - 1] == '0')
					ft_puterror("One of the map borders is open !");
			if (g_map[i - 1][j - 1] == ' ')
				if (!ft_check_arr_space(i - 1, j - 1, g_rows, g_cols))
					ft_puterror("Map is vulnerable !");
			g_map[i - 1][j - 1] == '2' ? num_sp++ : num_sp;
		}
	}
	if (!g_player.player || g_player.player > 1)
		ft_puterror("Player not Found or there is more than ONE Player!");
}
