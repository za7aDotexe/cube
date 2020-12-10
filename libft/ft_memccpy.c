/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:42:25 by razaha            #+#    #+#             */
/*   Updated: 2019/11/08 21:50:49 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)dst++ = *(unsigned char*)src++;
		if (*((unsigned char*)src) == (unsigned char)c)
		{
			*(unsigned char *)dst++ = *(unsigned char*)src++;
			return (dst++);
		}
	}
	return (NULL);
}
