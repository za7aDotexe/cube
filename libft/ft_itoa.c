/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:21:42 by razaha            #+#    #+#             */
/*   Updated: 2019/11/03 15:08:28 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		counter(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		i = 1;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

static void		ft_setnbr(int n, char *ptr)
{
	if (n > 9)
		ft_setnbr(n / 10, ptr - 1);
	*ptr = (n % 10) + 48;
}

char			*ft_itoa(int n)
{
	int		size;
	int		s;
	char	*ret;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = 0;
	size = counter(n);
	if (!(ret = ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		*ret++ = '-';
		n = -n;
		size -= 1;
		s++;
	}
	ft_setnbr(n, ret + size - 1);
	return (ret - s);
}
