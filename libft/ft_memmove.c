/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <razaha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:17:24 by razaha            #+#    #+#             */
/*   Updated: 2019/11/10 00:17:57 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			dst--;
			src--;
		}
		dst += 1;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
