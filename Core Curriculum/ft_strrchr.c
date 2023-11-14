/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:57:01 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/14 21:19:52 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The strrchr() function returns a pointer to the last occurrence of
// the character c in the string s.
// The strchr() and strrchr() functions return a pointer to the matched
//character or NULL if the character  is  not  found.
//The  terminating null byte is considered part of the string, so that
//if c is specified as '\0', these functions return a
//pointer to the terminator.
// #include <string.h>
// #include <stdio.h>

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	char	character;
	char	counter;

	character = c;
	counter = 0;
	while (*s != '\0')
	{
		if (*s == character)
		{
			counter = *s;
		}
		s++;
	}
	if (counter)
		return ((char *)s);
	else if (character == '\0')
		return ((char *)s + 1);
	else
		return (NULL);
}

// int main()
// {
//     int c = 69;
//     int c2 = 'b';
//     char    s[10] = "Anubis";
//     char    s2[10] = "Ragnar";
//     printf("String1: %s\n", s);
// 	printf("String2: %s\n", s2);
//     printf("First Character to be found: %c\n", c);
// 	printf("Second Character to be found: %c\n", c2);
//     printf("Print address of last occurence"
// 			"if found or null:%p\n", strchr(s, c));
//     printf("Print address of last occurence"
// 			"if found or null:%p\n", ft_strchr(s2, c2));
//     return (0);
// }