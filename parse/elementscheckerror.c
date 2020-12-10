/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementscheckerror.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:31:38 by razaha            #+#    #+#             */
/*   Updated: 2020/12/10 12:08:27 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void	ft_check_elements(void)
{
	g_window_width > 2560 ? g_window_width = 2560 : 0;
	g_window_height > 1440 ? g_window_height = 1440 : 0;
	if (!g_window_width || !g_window_height || g_window_width <= 0
	|| g_window_height <= 0)
		ft_puterror("Window Width or Window heigth INVALID");
	if (!g_notxt || open(g_notxt, O_RDONLY) == -1
	|| !ft_check_extension(g_notxt, ".xpm"))
		ft_puterror("North texture path INVALID !");
	if (!g_sotxt || open(g_sotxt, O_RDONLY) == -1
	|| !ft_check_extension(g_sotxt, ".xpm"))
		ft_puterror("South texture path INVALID !");
	if (!g_wetxt || open(g_wetxt, O_RDONLY) == -1
	|| !ft_check_extension(g_wetxt, ".xpm"))
		ft_puterror("West texture path INVALID !");
	if (!g_eatxt || open(g_eatxt, O_RDONLY) == -1
	|| !ft_check_extension(g_eatxt, ".xpm"))
		ft_puterror("East texture path INVALID !");
	if (!g_sprit || open(g_sprit, O_RDONLY) == -1
	|| !ft_check_extension(g_sprit, ".xpm"))
		ft_puterror("Sprite texture path INVALID !");
	if (g_fcol < 0 || g_ccol < 0)
		ft_puterror("INVALID CIEL/FLOOR OR UNSETED !");
}
