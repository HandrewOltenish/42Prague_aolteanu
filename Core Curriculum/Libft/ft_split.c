/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:28 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/08 19:32:34 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_split
// Prototype char **ft_split(char const *s, char c);
// Turn in files -
// Parameters s: The string to be split.
// c: The delimiter character.
// Return value The array of new strings resulting from the split.
// NULL if the allocation fails.
// External functs. malloc, free
// Description Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must end
// with a NULL pointer.

#include "libft.h"

size_t	ft_strlcpy(char	*dst,	const char	*src, size_t	size)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size < 1)
		return (count);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
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

int	ft_countwords(const char *s, char d)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == d)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			words++;
		}
		while (s[i] && s[i] != d)
		{
			i++;
		}
	}
	return (words);
}

char	*ft_getword(char *s, char d, size_t *i)
{
	char	*word;
	size_t	start;
	size_t	end;
	size_t	wordlength;

	start = *i;
	end = *i;
	while (s[end] != '\0' && s[end] != d)
	{
		end++;
	}
	*i = end;
	wordlength = end - start;
	word = (char *)malloc(sizeof(char) * (wordlength + 1));
	if (word == 0)
	{
		return (0);
	}
	ft_strlcpy(word, &s[start], (wordlength + 1));
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	array = (char **)malloc(sizeof(char *) * ((ft_countwords(s, c)) + 1));
	if (array == 0)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			array[j] = ft_getword((char *)s, c, &i);
			if (array[j] == 0)
				return (0);
			j++;
		}
	}
	array[j] = 0;
	return (array);
}

// int main()
// {

//     const char *string = "I like tacos";
//     char delimiter = ' ';
// 	printf("String to be split: %s\n", string);
// 	char **result = ft_split(string, delimiter);
//     if (result == 0)
// 	{
//         printf("Failed to allocate memory or input string is NULL.\n");
//         return (1);
//     }
//     for (int i = 0; result[i] != 0; i++)
// 	{
//         printf("Split %d: %s\n", i + 1, result[i]);
//         free(result[i]);
//     }
//     free(result);
//     return (0);
// }
