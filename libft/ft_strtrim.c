/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:05:14 by razaha            #+#    #+#             */
/*   Updated: 2019/11/07 22:37:50 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*backtrim(char *s1, char *set)
{
	size_t len;
	size_t reset;

	len = ft_strlen(s1);
	s1 += len - 1;
	while (len)
	{
		reset = 0;
		while (*set)
		{
			if (*set == *s1)
			{
				s1--;
				break ;
			}
			set++;
			reset++;
		}
		if (!*set)
			*(s1 + 1) = 0;
		set -= reset;
		len--;
	}
	return (0);
}

static	char	*fronttrim(char *s1, char *set)
{
	size_t reset;

	while (*s1)
	{
		reset = 0;
		while (*set)
		{
			if (*set == *s1)
			{
				s1++;
				break ;
			}
			set++;
			reset++;
		}
		if (!*set)
			return ((char *)s1);
		set -= reset;
	}
	return ("");
}

static	size_t	ft_strlen_p(const char *s)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	str[ft_strlen_p(s1) + 1];
	char	*trim;
	char	*ret;
	size_t	trimlen;

	if (!s1)
		return (NULL);
	if (!*s1 || !set)
		return (ft_calloc(1, 1));
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	trim = fronttrim(str, (char *)set);
	backtrim(trim, (char *)set);
	trimlen = ft_strlen(trim);
	if (!(ret = malloc(sizeof(char) * trimlen + 1)))
		return (NULL);
	ft_strlcpy(ret, trim, trimlen + 1);
	return (ret);
}
