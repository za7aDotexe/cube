/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:22:36 by razaha            #+#    #+#             */
/*   Updated: 2019/11/08 21:35:58 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;

	if (src == dst)
		ret = ft_strlen(src) + size;
	if (!dst && !size)
		ret = ft_strlen(src);
	else
	{
		ret = ft_strlen(dst) + ft_strlen(src);
		if (ft_strlen(dst) >= size)
			return (ft_strlen(src) + size);
		ft_strlcpy(dst + ft_strlen(dst), src, size - ft_strlen(dst));
	}
	return (ret);
}
