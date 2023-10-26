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

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char	*s, int c)
{
	unsigned char	character;

	character = c;
	while (*s != '\0')
	{
		if (*s == character)
		{
			return ((char *)s);
		}
		else
			s++;
	}
	return ((char *)s);
}

// int main()
// {
//     int c = 69;
//     int c2 = 98;
//     char    s[10] = "Anubis";
//     char    s2[10] = "Ragnar";
//     printf("String: %s\n", s);
//     printf("Character to be found: %c\n", c);
//     printf("Print address if found or null:%p\n", strchr(s, c));
//     printf("Print address if found or null:%p\n", ft_strchr(s2, c2));
//     return (0);
// }