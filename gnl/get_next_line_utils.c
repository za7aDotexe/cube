/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:23:37 by razaha            #+#    #+#             */
/*   Updated: 2019/11/13 05:47:28 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(s))
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	return (*(char *)s == (char)c) ? (char *)s : NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t sn;

	sn = n;
	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (dst - sn);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_memcpy(ret, s1, len);
	ret[len] = 0;
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	sumlen;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	sumlen = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = malloc(sizeof(char) * (sumlen + 1))))
		return (NULL);
	ft_memcpy(ret, s1, ft_strlen(s1));
	ft_memcpy(ret + ft_strlen(s1), s2, ft_strlen(s2));
	ret[sumlen] = 0;
	return (ret);
}
