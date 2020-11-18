/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementscheckerror.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:31:38 by razaha            #+#    #+#             */
/*   Updated: 2020/11/18 19:30:31 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void    ft_check_elements()
{
    WINDOW_WIDTH > 2560 ? WINDOW_WIDTH = 2560 : 0;
    WINDOW_HEIGHT > 1440 ? WINDOW_HEIGHT = 1440 : 0;
    
    if (!NOTXT || open(NOTXT, O_RDONLY) == -1)
        ft_puterror("North texture path not valid or xpm file empty !");
    if (!SOTXT || open(SOTXT, O_RDONLY) == -1)
        ft_puterror("South texture path not valid or xpm file empty !");
    if (!WETXT || open(WETXT, O_RDONLY) == -1)
        ft_puterror("West texture path not valid or xpm file empty !");
    if (!EATXT || open(EATXT, O_RDONLY) == -1)
        ft_puterror("East texture path not valid or xpm file empty !");
    if (!SPRIT || open(SPRIT, O_RDONLY) == -1)
        ft_puterror("Sprite texture path not valid or xpm file empty !");
    if (!player.player || player.player > 1)
        ft_puterror("Player not found or there is more than one player!");
}