/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:47:45 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/05 15:08:04 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  strcat() function appends the src string to the dest string,
// overwriting the terminating null byte ('\0') at the end of dest, and then
// adds a terminating null byte.  The strings may not overlap, and the
// dest string must have enough space for the result.  If dest is not large
// enough, program behavior is unpredictable; buffer overruns are a favorite
// avenue for attacking secure programs. The strncat() function is similar,
// except that
//
// *  it will use at most n bytes from src; and
// *  src does not need to be null-terminated if it contains n or more bytes.
// As with strcat(), the resulting string in dest is always null-terminated.
// If src contains n or more bytes, strncat() writes n+1 bytes to dest
// (n from src plus the terminating null byte).  Therefore, the size of dest
// must be at least strlen(dest)+n+1.
//A simple implementation of strncat() might be:

        //    char *
        //    strncat(char *dest, const char *src, size_t n)
        //    {
        //        size_t dest_len = strlen(dest);
        //        size_t i;

        //        for (i = 0 ; i < n && src[i] != '\0' ; i++)
        //            dest[dest_len + i] = src[i];
        //        dest[dest_len + i] = '\0';
		//
		//		  return (dest);

#include <stdio.h>

char * ft_strncat (char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest [i] != '\0')
		i++;
	while (dest[j] != '\0' && j < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

// int	main()
// {
// 	char	dest[17] = "It is ";
// 	char	*src = "What it is";
// 	char	*s = ft_strncat(dest, src, 17);

// 	printf("Destination: %s\nSource: %s\nConcatenation: %s\n", dest, src, s);
// 	return (0);
// }