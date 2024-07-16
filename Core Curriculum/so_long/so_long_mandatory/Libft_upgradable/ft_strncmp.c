/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:30:13 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/07 17:35:27 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strcmp() returns an integer indicating the result of the comparison,
//as follows:
//
//		• 0, if the s1 and s2 are equal;
//
//     	• a negative value if s1 is less than s2;
//
//      • a positive value if s1 is greater than s2.
//
//      The strncmp() function is similar, except it compares only the first
//	(at most) n bytes of s1 and s2.
//		The strcmp() and strncmp() functions return an integer
//	less than, equal to, or greater than zero if s1 (or the  first  n
//	bytes thereof) is found, respectively, to be less than,
//	to match, or be greater than s2.

// #include <string.h>
// #include <stdio.h>

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n && n != 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char )s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (0);
}

// int	main(void)
// {
// 	printf("Which is bigger?\nLuther\nZeke\nIf s1 > s2 type 1\n");
// 	printf("If s1 < s2 type -1\n");
// 	printf("If s1 == s2 type 0\n");
// 	printf("Let's see the result: %i\n", ft_strncmp("Luther", "Zeke", 5));
// 	printf("Let's see the result: %i\n", strncmp("Luther", "Zeke", 5));
// 	return (0);
// }

// int	main(void)
// {
// 	char *s = "test\200";
// 	char *s2 = "test\0";
// 	printf("%i\n", ft_strncmp(s, s2, 6));
// 	printf("%i\n", strncmp(s, s2, 6));
// 	return (0);
// }