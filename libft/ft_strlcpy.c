/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:49:00 by razaha            #+#    #+#             */
/*   Updated: 2019/11/10 00:06:04 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;

	len = ft_strlen(src);
	if (size > 0)
	{
		while (--size && *src != 0)
		{
			ft_memset(dst, *(char *)src, 1);
			dst++;
			src++;
		}
		*dst = 0;
	}
	return (len);
}
