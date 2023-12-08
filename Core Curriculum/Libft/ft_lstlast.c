/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:34:56 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/08 21:40:12 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstlast
// Prototype t_list *ft_lstlast(t_list *lst);
// Turn in files -
// Parameters lst: The beginning of the list.
// Return value Last node of the list
// External functs. None
// Description Returns the last node of the list.

#include "libft.h"
#include <stdlib.h> 
#include <stdio.h>

t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
		elem->content = NULL;
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}
