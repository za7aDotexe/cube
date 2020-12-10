/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:49:29 by razaha            #+#    #+#             */
/*   Updated: 2019/11/06 16:51:36 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int lstsize;

	lstsize = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		lstsize++;
	}
	return (lstsize);
}
