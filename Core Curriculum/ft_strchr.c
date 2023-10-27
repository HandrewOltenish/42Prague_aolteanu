/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:53:02 by marvin            #+#    #+#             */
/*   Updated: 2023/10/25 15:53:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The strchr() function returns a pointer to the first occurrence
//of the character c in the string s.
//The  terminating null byte is considered part of the string, so that
//if c is specified as '\0', these functions return a
//pointer to the terminator.
#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char	*s, int c)
{
	char	character;

	character = c;
	while (*s != '\0')
	{
		if (*s != character)
			s++;
	}
	if (*s == character)
		return ((char *)s);
	else if (character == '\0')
		return ((char *)s + 1);
	else
		return (NULL);
}

// int main()
// {
//     int c = 69;
//     int c2 = '\0';
//     char    s[10] = "Anubis";
//     char    s2[10] = "Ragnar";
//     printf("String1: %s\n", s);
// 	printf("String2: %s\n", s2);
//     printf("First Character to be found: %c\n", c);
// 	printf("Second Character to be found: %c\n", c2);
//     printf("Print address if found or null:%p\n", strchr(s, c));
//     printf("Print address if found or null:%p\n", ft_strchr(s2, c2));
//     return (0);
// }