/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:40:27 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/13 12:39:29 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_strmapi
// Prototype char *ft_strmapi(char const *s, char (*f)(unsigned
// int, char));
// Turn in files -
// Parameters s: The string on which to iterate.
// f: The function to apply to each character.
// Return value The string created from the successive applications
// of ’f’.
// Returns NULL if the allocation fails.
// External functs. malloc
// Description Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	f(unsigned int index, char character)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (index + 1));
	str[index] = character + 1;
	return (str[index]);
}

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	char	*temp_str;
	char	*str;
	int		index;
	size_t	length;

	index = 0;
	length = ft_strlen(s);
	temp_str = (char *)malloc(sizeof(char) * (length + 1));
	while (s[index] != '\0')
	{
		temp_str[index] = (*f)(index, s[index]);
		index++;
	}
	temp_str[index] = '\0';
	str = (char *)malloc(sizeof(char) * (index + 1));
	str = temp_str;
	if (str == 0);
		return (NULL);
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = (char *)malloc(4);
// 	str = "ABC";
//	printf("Original String: %s\n
//	String after applying function f: %s\n", str, ft_strmapi(str, f));
//    free(str);
//     return (0);
// }