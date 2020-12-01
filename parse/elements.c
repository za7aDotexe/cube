/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:31:41 by razaha            #+#    #+#             */
/*   Updated: 2020/12/01 16:55:33 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void	ft_textu2(char c, char c2, char *line)
{
	if (c == 'W' && c2 == 'E')
	{
		if (g_wetxt)
			ft_puterror("Double INCLUDE of west texture");
		g_wetxt = ft_trim_spaces(line);
	}
	if (c == 'E' && c2 == 'A')
	{
		if (g_eatxt)
			ft_puterror("Double INCLUDE of east texture");
		g_eatxt = ft_trim_spaces(line);
	}
	if (c == 'S' && c2 == ' ')
	{
		if (g_sprit)
			ft_puterror("Double INCLUDE of sprit texture");
		g_sprit = ft_trim_spaces(line);
	}
}

void	ft_textu(char c, char c2, char *line)
{
	line = line + 2;
	while (*line == ' ' && *line != '\n')
		line++;
	if (c == 'N' && c2 == 'O')
	{
		if (g_notxt)
			ft_puterror("Double INCLUDE of north texture");
		g_notxt = ft_trim_spaces(line);
	}
	if (c == 'S' && c2 == 'O')
	{
		if (g_sotxt)
			ft_puterror("Double INCLUDE of south texture");
		g_sotxt = ft_trim_spaces(line);
	}
	ft_textu2(c, c2, line);
}

void	ft_fill_resolution(char *line)
{
	char **s1;

	s1 = ft_split(line, ' ');
	if (g_window_width || g_window_height)
		ft_puterror("Double Resolution elements !");
	if (*(s1 + 1) && *(s1 + 2) && !*(s1 + 3))
	{
		g_window_width = ft_atoi(*(s1 + 1));
		g_window_height = ft_atoi(*(s1 + 2));
	}
	ft_free(s1);
}

void	ft_fill_floorciel_color2(char *line, int r, int g, int b)
{
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		ft_puterror("INVALID color range ! must be between 0 and 255");
	if (*line == 'F')
	{
		if (g_fcol >= 0)
			ft_puterror("DOUBLE floor color elements !");
		g_fcol = rgb_to_hex(r, g, b);
	}
	if (*line == 'C')
	{
		if (g_ccol >= 0)
			ft_puterror("DOUBLE ciel color elements !");
		g_ccol = rgb_to_hex(r, g, b);
	}
}

void	ft_fill_floorciel_color(char *line)
{
	char	**s1;
	int		r;
	int		g;
	int		b;

	g = 0;
	r = 0;
	while (line[r] != '\0')
		if (line[r++] == ',')
			g++;
	if (g != 2)
		ft_puterror("INVALID color Syntax !");
	r = 0;
	g = 0;
	b = 0;
	s1 = ft_split(line + 1, ',');
	if (*(s1) && *(s1 + 1) && *(s1 + 2) && !*(s1 + 3))
	{
		r = ft_atoi(*(s1));
		g = ft_atoi(*(s1 + 1));
		b = ft_atoi(*(s1 + 2));
	}
	ft_fill_floorciel_color2(line, r, g, b);
	ft_free(s1);
}
