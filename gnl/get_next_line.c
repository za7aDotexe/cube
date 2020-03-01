/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:25:16 by razaha            #+#    #+#             */
/*   Updated: 2019/11/18 02:01:42 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strclr(char *s)
{
	while (*s != '\0')
		*s++ = '\0';
}

char	*check_rest(char **rest, char **line)
{
	char	*ptr_nl;
	char	*tmp;

	ptr_nl = NULL;
	*line = ft_strdup("");
	if (*rest)
	{
		free(*line);
		if ((ptr_nl = ft_strchr(*rest, '\n')))
		{
			*ptr_nl = '\0';
			*line = ft_strdup(*rest);
			tmp = *rest;
			*rest = ft_strdup(++ptr_nl);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(*rest);
			ft_strclr(*rest);
		}
	}
	return (ptr_nl);
}

int		free_rest_and_return(int ret, char **rest)
{
	if (ret == 0 && *rest)
	{
		free(*rest);
		*rest = NULL;
	}
	return (ret < 1) ? ret : 1;
}

int		get_line(int fd, char **rest, char **line)
{
	char		*rdo;
	char		*ptr_nl;
	char		*tmp;
	int			ret;

	ret = 1;
	if (!(rdo = malloc((BUFFER_SIZE + 1 * sizeof(char)))))
		return (-1);
	ptr_nl = check_rest(&rest[fd], line);
	while (!ptr_nl && (ret = read(fd, rdo, BUFFER_SIZE)) > 0)
	{
		rdo[ret] = '\0';
		if ((ptr_nl = ft_strchr(rdo, '\n')))
		{
			*ptr_nl = '\0';
			tmp = rest[fd];
			rest[fd] = ft_strdup(++ptr_nl);
			free(tmp);
		}
		tmp = *line;
		*line = ft_strjoin(*line, rdo);
		free(tmp);
	}
	free(rdo);
	return (free_rest_and_return(ret, &rest[fd]));
}

int		get_next_line(int fd, char **line)
{
	static char *rest[4864];

	*line = NULL;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 0)
		return (-1);
	return (get_line(fd, &rest[fd], line));
}
