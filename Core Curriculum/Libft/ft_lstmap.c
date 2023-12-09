/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:33:53 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/09 21:34:39 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*resfct;

	(void)del;
	if (!lst || !f)
		return (NULL);
	resfct = ft_lstnew(f(lst->content));
	if (!(resfct))
		return (NULL);
	res = resfct;
	lst = lst->next;
	while (lst)
	{
		resfct = ft_lstnew(f(lst->content));
		if (!(resfct))
		{
			ft_lstclear(&resfct, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&res, resfct);
	}
	return (res);
}
