/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:12:10 by razaha            #+#    #+#             */
/*   Updated: 2019/11/07 22:09:05 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(ret, s + start, len);
	ret[len] = 0;
	return (ret);
}
