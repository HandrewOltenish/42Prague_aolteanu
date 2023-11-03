/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:59:45 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/03 17:55:03 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

//check malloc
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	char	*substring;
	int		index;

	index = 0;
	if (s == 0 || len == 0)
		return (0);
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == 0)
		return (0);
	while (s[start] != '\0' && len > 0)
	{
		substring[index] = s[start];
		index++;
		start++;
		len--;
	}
	substring[index] = '\0';
	return (substring);
}

// int	main()
// {
// 	char const	*s = "Ramboo";
// 	char *result = ft_substr(s, 2, 4);

// 	printf("%s\n%s\n", s, result);
// 	free(result);
	
// 	return (0);
// }