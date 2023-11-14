/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:41:59 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/14 21:18:15 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <bsd/string.h>

//The strlcat() function appends the NUL-terminated string src to the end
//of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi‐
//nating the result.
// compile it like this "cc -lbsd ft_strlcat.c"

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	char		*pointer_dst;
	const char	*pointer_src;
	size_t		count;
	size_t		size_dst;

	size_dst = strlen(dst);
	pointer_dst = dst;
	pointer_src = src;
	count = 0;
	while (count <= (size - size_dst - 1))
	{
		if (pointer_src[count] == '\0')
		{
			pointer_dst[strlen(dst) + count] = '\0';
		}
		pointer_dst[strlen(dst) + count] = pointer_src[count];
		count++;
	}
	return (strlen(dst) - 1);
}

// int	main(void)
// {
// 	char	dst[] = "01234";
// 	char	src[] = "56789";
// 	char	dst2[] = "01234";
// 	char	src2[] = "56789";
// 	printf("Source: %s\n", src);
// 	printf("Destination: %s\n", dst);
// 	printf("Concatenated String Size: %zu\n", strlcat(dst, src, 15));
// 	printf("Concatenated String: %s\n", dst);
// 	printf("Source2: %s\n", src2);
// 	printf("Destination2: %s\n", dst2);
// 	printf("Concatenated String2 Size: %zu\n", ft_strlcat(dst2, src2, 15));	
// 	printf("Concatenated String2: %s\n", dst2);
// 	return (0);