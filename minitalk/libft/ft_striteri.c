/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:16:21 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/08 21:12:25 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_striteri
// Prototype void ft_striteri(char *s, void (*f)(unsigned int,
// char*));
// Turn in files -
// Parameters s: The string on which to iterate.
// f: The function to apply to each character.
// Return value None
// External functs. None
// Description Applies the function ’f’ on each character of
// the string passed as argument, passing its index
// as first argument. Each character is passed by
// address to ’f’ to be modified if necessary.

// #include <stdio.h>
// #include <stdlib.h>

#include "libft.h"

void	f(unsigned int index, char *s)
{
	if (s[index] != 'A')
	{
		s[index] = 'a';
	}
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL)
	{
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}

// int	main(void)
// {
// 	char	str[4] = "ABC";
//	
// 	printf("String: %s\n", str);
// 	ft_striteri(str, f);
// 	printf("String after f: %s\n", str);
// 	return (0);
// }