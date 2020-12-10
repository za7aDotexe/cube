/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:43:10 by razaha            #+#    #+#             */
/*   Updated: 2019/11/03 22:14:30 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	sumlen;

	if (!s1)
		return (NULL);
	sumlen = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = malloc(sizeof(char) * (sumlen + 1))))
		return (NULL);
	ft_memcpy(ret, s1, ft_strlen(s1));
	ft_memcpy(ret + ft_strlen(s1), s2, ft_strlen(s2));
	ret[sumlen] = 0;
	return (ret);
}
