/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:54:49 by razaha            #+#    #+#             */
/*   Updated: 2019/11/04 01:05:21 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int inb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		inb = n * -1;
	}
	else
		inb = n;
	if (inb > 9)
		ft_putnbr_fd(inb / 10, fd);
	ft_putchar_fd(inb % 10 + '0', fd);
}
