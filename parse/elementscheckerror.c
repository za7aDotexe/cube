/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementscheckerror.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:31:38 by razaha            #+#    #+#             */
/*   Updated: 2020/11/20 18:16:50 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void    ft_check_elements()
{
    WINDOW_WIDTH > 2560 ? WINDOW_WIDTH = 2560 : 0;
    WINDOW_HEIGHT > 1440 ? WINDOW_HEIGHT = 1440 : 0;
    if (!WINDOW_WIDTH || !WINDOW_HEIGHT || WINDOW_WIDTH <= 0 || WINDOW_HEIGHT <= 0)
        ft_puterror("Window Width or Window heigth INVALID");
    if (!NOTXT || open(NOTXT, O_RDONLY) == -1)
        ft_puterror("North texture path INVALID or xpm file EMPTY !");
    if (!SOTXT || open(SOTXT, O_RDONLY) == -1)
        ft_puterror("South texture path INVALID or xpm file EMPTY !");
    if (!WETXT || open(WETXT, O_RDONLY) == -1)
        ft_puterror("West texture path INVALID or xpm file EMPTY !");
    if (!EATXT || open(EATXT, O_RDONLY) == -1)
        ft_puterror("East texture path INVALID or xpm file EMPTY !");
    if (!SPRIT || open(SPRIT, O_RDONLY) == -1)
        ft_puterror("Sprite texture path INVALID or xpm file EMPTY !");
    if (!player.player || player.player > 1)
        ft_puterror("Player not Found or there is more than ONE player!");
}