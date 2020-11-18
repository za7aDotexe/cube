/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:31:41 by razaha            #+#    #+#             */
/*   Updated: 2020/11/18 18:56:53 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void		ft_textu(char c, char c2, char *line)
{
	line = line + 2;
	while (*line == ' ' && *line != '\n')
		line++;
	if (c == 'N' && c2 == 'O')
		NOTXT = line;
	if (c == 'S' && c2 == 'O')
		SOTXT = line;
	if (c == 'W' && c2 == 'E')
		WETXT = line;
	if (c == 'E' && c2 == 'A')
		EATXT = line;
	if (c == 'S' && c2 == ' ')
		SPRIT = line;

}

void		ft_fill_resolution(char *line)
{
	char **s1;

	s1 = ft_split(line, ' ');
	WINDOW_WIDTH = ft_atoi(*(s1 + 1));
	WINDOW_HEIGHT = ft_atoi(*(s1 + 2));
}

void		ft_fill_floorciel_color(char *line)
{
	char	**s1;
	char	**s2;
	int		r;
	int		g;
	int		b;

	s1 = ft_split(line, ' ');
	s2 = ft_split(*(s1 + 1), ',');
	r = ft_atoi(*(s2));
	g = ft_atoi(*(s2 + 1));
	b = ft_atoi(*(s2 + 2));
	if (*line == 'F')
		FCOL = rgb_to_hex(r, g, b);
	if (*line == 'C')
		CCOL = rgb_to_hex(r, g, b);
}
