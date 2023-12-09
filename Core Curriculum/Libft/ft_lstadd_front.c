/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:25:31 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/09 20:43:34 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstadd_front
// Prototype void ft_lstadd_front(t_list **lst, t_list *new);
// Turn in files -
// Parameters lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the node ’new’ at the beginning of the list.

#include "libft.h"
#include <stdlib.h> 
#include <stdio.h>

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
