/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:47:34 by razaha            #+#    #+#             */
/*   Updated: 2019/11/03 22:11:52 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_spounter(char *s, char *del)
{
	int		i;
	char	*next_s;

	i = 0;
	if (*s != *del && *s)
		i++;
	while (*s)
	{
		next_s = s + 1;
		if (*s == *del && *next_s != *del && *next_s != '\0')
			i++;
		if (*s == *del)
			*s = 0;
		s++;
	}
	return (i);
}

static	int			ft_pointer(char *s, char **tab, size_t slen)
{
	char *next_s;

	if (*s)
	{
		if (!(*tab++ = ft_strdup(s)))
			return (0);
	}
	while (slen--)
	{
		next_s = s + 1;
		if (*s == 0 && *next_s)
		{
			if (!(*tab++ = ft_strdup(next_s)))
				return (0);
		}
		s++;
	}
	return (1);
}

static	size_t		ft_strlen_p(const char *s)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

char				**ft_split(char const *s, char c)
{
	char	**tab;
	char	word[ft_strlen_p(s) + 1];
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	ft_strlcpy(word, s, ft_strlen_p(s) + 1);
	if (!(tab = ft_calloc((ft_spounter(word, &c) + 1), sizeof(char *))))
		return (NULL);
	if (ft_pointer(word, tab, s_len) == 0)
	{
		while (*tab)
			free(*tab++);
		free(tab);
		return (NULL);
	}
	return (tab);
}
