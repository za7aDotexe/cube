/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:52:51 by razaha            #+#    #+#             */
/*   Updated: 2019/11/03 22:15:13 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*ret;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(ret = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (len)
	{
		*(ret + len - 1) = f(len - 1, *(s + len - 1));
		len--;
	}
	return (ret);
}
