/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:15:35 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/06 22:53:51 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implement the following functions in order to easily use your lists.
// Function name ft_lstnew
// Prototype t_list *ft_lstnew(void *content);
// Turn in files -
// Parameters content: The content to create the node with.
// Return value The new node
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL.

#include "libft.h"
#include <stdlib.h> 
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
