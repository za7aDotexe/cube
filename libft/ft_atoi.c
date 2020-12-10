/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 00:51:40 by razaha            #+#    #+#             */
/*   Updated: 2020/12/10 18:39:54 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_atoi(const char *str2)
{
	int		res;
	char	*str;
	char	*temp;

	str = ft_strtrim(str2, " ");
	res = 0;
	temp = str;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + *str - 48;
		else
		{
			free(temp);
			return (-1);
		}
		str++;
	}
	free(temp);
	return (res);
}
