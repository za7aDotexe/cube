/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:50:25 by razaha            #+#    #+#             */
/*   Updated: 2019/11/10 00:00:51 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nedlen;
	size_t	haylen;
	size_t	s;

	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	nedlen = ft_strlen(needle);
	haylen = ft_strlen(haystack);
	while (nedlen <= len-- && (nedlen <= haylen) && *haystack)
	{
		s = 0;
		while (needle[s] == *haystack)
		{
			if (!(needle[s + 1]))
				return ((char *)haystack - s);
			haystack++;
			s++;
		}
		haystack -= s - 1;
	}
	return (NULL);
}
