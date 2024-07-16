/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:45:18 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/05 12:19:06 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// External Functions: malloc
// Description: Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.
// s1: The string to be trimmed.
// set: The reference set of characters to trim.
// Returns: The trimmed string.
// NULL if the allocation fails.

//	My logic behind this: Take string, parse it from start
// and from the end, if you find the iterations of set,
// skip them, until you reach the string
// Then count how many bites the string has and allocate
// them to its copy
// At last, copy the string to the copy.

// #include <stdio.h>
// #include <stdlib.h>

#include "libft.h"

static int	ft_charcmp(char c, const	char *set)
{
	while (*set)
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*s1_copy;
	int		start;
	int		end;
	int		index;

	start = 0;
	index = 0;
	end = ft_strlen((char *)s1);
	while (s1[start] && ft_charcmp(s1[start], set))
		start++;
	while (end > start && ft_charcmp(s1[end - 1], set))
		end--;
	s1_copy = (char *)malloc((end - start + 1) * sizeof(char));
	if (!s1_copy)
	{
		return (NULL);
	}
	while (start < end)
	{
		s1_copy[index] = s1[start];
		index++;
		start++;
	}
	s1_copy[index] = '\0';
	return (s1_copy);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*set;
// 	char	*s1_copy;

// 	s1 = "Bada Bing Bada Boom Bada";
// 	set = "Bada";
// 	s1_copy = ft_strtrim(s1, set);
// 	printf("String: %s\nTrimmer: %s\nTrimmed String: %s\n", s1, set, s1_copy);
// 	return (0);
// }
