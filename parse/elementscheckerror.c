/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementscheckerror.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:31:38 by razaha            #+#    #+#             */
/*   Updated: 2020/11/17 19:36:53 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../cube.h"

void    ft_check_elements()
{
    if (!NOTXT)
        ft_puterror("Noth Textur !!");
    if (!SOTXT)
        ft_puterror("South Textur !!");
    if (!WETXT)
        ft_puterror("West Textur !!");
    if (!EATXT)
        ft_puterror("East Textur !!");
    if (!SPRIT)
        ft_puterror("Sprite Textur !!");
    if(!player.player)
        ft_puterror("Player Not Found !");
}