/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:59:45 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/08 19:12:53 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

//check malloc
// #include <stdlib.h>
// #include <stdio.h>

#include "libft.h"
#include <mcheck.h>

char	*ft_strdup(const char	*s)
{
	int			counter;
	char		*result;

	counter = 0;
	while (s[counter])
	{
		counter++;
	}
	result = malloc(sizeof(char) * (counter + 1));
	if (result == 0)
		return (NULL);
	counter = 0;
	while (s[counter])
	{
		result[counter] = s[counter];
		counter++;
	}
	result[counter] = '\0';
	return (result);
}

size_t	ft_strlen(const char	*s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

//consider using functions from the past, like ft_strlcpy

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	char		*substring;
	size_t		index;
	size_t		str_len;

	index = 0;
	str_len = ft_strlen(s);
	if (s == 0 || start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len;
	substring = (char *)malloc((len + 1) * sizeof(*s));
	if (substring == 0)
		return (0);
	while (s[index] != '\0' && index < len)
	{
		substring[index] = s[start];
		index++;
		start++;
	}
	substring[index] = '\0';
	return (substring);
}

// Inspiration function #1 - passes some of the tests (tripouille)
// ---------------------------------------------------------------
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*new_str;
// 	size_t	i;
// 	size_t	j;

// 	if (!s || !(new_str = (char *)malloc(len + 1)))
// 		return (0);
// 	i = start;
// 	j = 0;
// 	while (i < ft_strlen(s) && j < len)
// 		new_str[j++] = s[i++];
// 	new_str[j] = '\0';
// 	return (new_str);
// }
// ---------------------------------------------------------------
// Inspiration function #2 - passes some of the tests (tripouille)
// ---------------------------------------------------------------
// char	*ft_substr(const char *s, unsigned int start, size_t len)
// {
// 	char	*ret;

// 	if (!s)
// 		return (0);
// 	if (ft_strlen(s) < start)
// 		len = 0;
// 	if (ft_strlen(s + start) < len)
// 		len = ft_strlen(s + start);
// 	ret = malloc(sizeof(char) * (len + 1));
// 	if (!ret)
// 		return (0);
// 	ft_strlcpy(ret, s + start, len + 1);
// 	return (ret);
// }
// ---------------------------------------------------------------
// int	main()
// {
// 	char const	*s = "123456789";
// 	char *result = ft_substr(s, 1, 1);
// 	int	comparison = 2;
// 	printf("String: %s\nSubstring: %s\n", s, result);
// //	printf("Mcheck: %i\n", mcheck(result, 2));
// 	if (!strcmp(result, ""))
// 		comparison = 3;
// 	else
// 		comparison = 0;
// 	printf("Comparison: %i\n", comparison);
// //	free(result);
// 	return (0);
// }