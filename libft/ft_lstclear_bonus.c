/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:40:50 by razaha            #+#    #+#             */
/*   Updated: 2019/11/07 00:43:47 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;
	t_list *beg;

	if (!lst)
		return ;
	beg = *lst;
	while (beg)
	{
		temp = beg;
		beg = beg->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
