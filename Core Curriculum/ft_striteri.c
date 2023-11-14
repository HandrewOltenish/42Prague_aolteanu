/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UNFINISHED_ft_striteri.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:16:21 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/14 15:02:33 by aolteanu         ###   ########.fr       */
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

#include <stdio.h>
#include <stdlib.h>

void	f(unsigned int index, char *s)
{
	if (s[index] != 'A')
	{
		s[index] = 'a';
	}
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return ;
	while (s[index] != '\0')
	{
		f(index, s);
		index++;
	}
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