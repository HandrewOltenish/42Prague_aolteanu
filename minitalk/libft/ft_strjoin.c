/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:43:57 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/14 21:54:09 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’
// Returns the new string or NULL if the allocation fails.

// #include <stdio.h>
// #include <stdlib.h>

#include "libft.h"

// The following function is 20 lines
char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*join;
	size_t	size1;
	size_t	size2;

	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	if (s1 == 0 || s2 == 0)
		return (0);
	join = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (join == 0)
		return (0);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	join -= (size1 + size2);
	return (join);
}

// int	main()
// {
// 	char const	*s1 = "TETSUOOOO";
// 	char const	*s2 = "KANEDAAAAAA";
// 	char 		*result;
// 	result = ft_strjoin(s1, s2);
// 	printf("%s\n%s\n%s\n", s1, s2, result);
// 	free(result);
// 	return (0);
// }
// -----------------------------------------------
// ft_strjoin can also be written like this in 16 lines
// -----------------------------------------------
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*join;
// 	size_t	size1;
// 	size_t	size2;
//
// 	size1 = ft_strlen((char *)s1);
// 	size2 = ft_strlen((char *)s2);
// 	if (!s1 || !s2 || !(join = malloc(size1 + size2 + 1)))
// 		return (NULL);
// 	join[size1 + size2] = '\0';
// 	while (size2--)
// 		join[size1 + size2] = s2[size2];
// 	while (size1--)
// 		join[size1] = s1[size1];
// 	return (join);
// }
// -----------------------------------------------
// Or it can be written like this in 30 lines
// -----------------------------------------------
// char	*ft_strjoin(char const	*s1, char const	*s2)
// {
// 	char	*join;
// 	size_t	size1;
// 	size_t	size2;
// 	int		index1;
// 	int		index2;
//
// 	index1 = 0;
// 	index2 = 0;
// 	size1 = ft_strlen((char *)s1);
// 	size2 = ft_strlen((char *)s2);
// 	if (s1 == 0 || s2 == 0)
// 		return (0);
// 	join = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
// 	if (join == 0)
// 		return (0);
// 	while (s1[index1] != '\0')
// 	{
// 		join[index1] = s1[index1];
// 		index1++;
// 	}
// 	while (s2[index2] != '\0')
// 	{
// 		join[index1] = s2[index2];
// 		index1++;
// 		index2++;
// 	}
// 	join[index1] = '\0';
// 	return (join);
// }