/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:27:33 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/09 20:47:03 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstsize
// Prototype int ft_lstsize(t_list *lst);
// Turn in files -
// Parameters lst: The beginning of the list.
// Return value The length of the list
// External functs. None
// Description Counts the number of nodes in a list

#include "libft.h"
#include <stdlib.h> 
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	t_list		*tmp;
	int			i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
