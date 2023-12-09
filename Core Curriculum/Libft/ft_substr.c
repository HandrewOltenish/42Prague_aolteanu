/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:59:45 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/09 22:19:02 by aolteanu         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		newstr = (char *)malloc(1);
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	if (len > slen - start)
		len = slen - start;
	newstr = (char *)malloc(len + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s + start, len + 1);
	return (newstr);
}
