/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UNFINISHED_ft_strmapi.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:40:27 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/10 18:28:35 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_strmapi
// Prototype char *ft_strmapi(char const *s, char (*f)(unsigned
// int, char));
// Turn in files -
// Parameters s: The string on which to iterate.
// f: The function to apply to each character.
// Return value The string created from the successive applications
// of ’f’.
// Returns NULL if the allocation fails.
// External functs. malloc
// Description Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.

#include <stdio.h>
#include <unistd.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	
}