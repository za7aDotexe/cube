/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:31:41 by razaha            #+#    #+#             */
/*   Updated: 2020/11/21 11:42:13 by razaha           ###   ########.fr       */
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
		NOTXT = ft_strdup(line);
	if (c == 'S' && c2 == 'O')
		SOTXT = ft_strdup(line);
	if (c == 'W' && c2 == 'E')
		WETXT = ft_strdup(line);
	if (c == 'E' && c2 == 'A')
		EATXT = ft_strdup(line);
	if (c == 'S' && c2 == ' ')
		SPRIT = ft_strdup(line);
}

void	ft_free(char **s)
{
	int i;

	i=0;
	while(s[i])
		free(s[i++]);
	free(s);
}

void		ft_fill_resolution(char *line)
{
	char **s1;

	s1 = ft_split(line, ' ');
	if (WINDOW_WIDTH || WINDOW_HEIGHT)
		ft_puterror("Double Resolution elements !");
	WINDOW_WIDTH = ft_atoi(*(s1 + 1));
	WINDOW_HEIGHT = ft_atoi(*(s1 + 2));
	ft_free(s1);
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
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		ft_puterror("INVALID color range ! must be between 0 and 255");
	if (*line == 'F')
		FCOL = rgb_to_hex(r, g, b);
	if (*line == 'C')
		CCOL = rgb_to_hex(r, g, b);
	ft_free(s1);
	ft_free(s2);
}
