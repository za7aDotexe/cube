/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 00:14:55 by razaha            #+#    #+#             */
/*   Updated: 2019/11/08 02:06:47 by razaha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *keep;
	t_list *beg;

	if (!lst && !del)
		return (NULL);
	keep = ft_lstnew(f((lst->content)));
	beg = keep;
	while (lst)
		if (keep == NULL)
		{
			ft_lstclear(&beg, del);
			break ;
		}
		else
		{
			keep->content = f(lst->content);
			lst = lst->next;
			if (!lst)
				break ;
			keep->next = ft_lstnew(f(lst->content));
			keep = keep->next;
		}
	keep->next = NULL;
	return (beg);
}
