/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:01:07 by razaha            #+#    #+#             */
/*   Updated: 2020/12/10 14:02:12 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void	ft_fill_resolution(char *line)
{
	char **s1;

	s1 = ft_split(line, ' ');
	if (g_window_width || g_window_height)
		ft_puterror("Double Resolution elements !");
	if (*(s1 + 1) && *(s1 + 2) && !*(s1 + 3))
	{
		g_window_width = ft_p_atoi(*(s1 + 1));
		g_window_height = ft_p_atoi(*(s1 + 2));
	}
	ft_free(s1);
}
