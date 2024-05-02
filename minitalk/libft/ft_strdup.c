/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:29:18 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/08 19:10:30 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	The  strdup()  function  returns  a pointer to a new string which is
//	a duplicate of the string s.  Memory for the new string is ob‐
//	tained with malloc(3), and can be freed with free(3).

//to increment on same line you can use
// str2[counter] = str[counter++] on last line of loop

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#include "libft.h"

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

// int	main()
// {
// 	char	*our;
//
// 	our = ft_strdup("hello");
// 	free(our);
// 	return (0);
// }