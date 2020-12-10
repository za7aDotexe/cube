/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ciel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:55:03 by razaha            #+#    #+#             */
/*   Updated: 2020/12/10 12:08:35 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void	ft_fill_floorciel_color2(char *line, int r, int g, int b)
{
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		ft_puterror("INVALID color range !");
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

	r = 0;
	g = 0;
	b = 0;
	ft_check_comma(line);
	s1 = ft_split(line + 1, ',');
	if (*(s1) && *(s1 + 1) && *(s1 + 2) && !*(s1 + 3))
	{
		r = ft_p_atoi(*(s1));
		g = ft_p_atoi(*(s1 + 1));
		b = ft_p_atoi(*(s1 + 2));
	}
	else
		ft_puterror("INVALID color Syntax !");
	ft_fill_floorciel_color2(line, r, g, b);
	ft_free(s1);
}
