/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:41:59 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/07 17:36:14 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <bsd/string.h>

//The strlcat() function appends the NUL-terminated string src to the end
//of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi‐
//nating the result.
// compile it like this "cc -lbsd ft_strlcat.c"

#include "libft.h"
#include <bsd/string.h>

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

size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	size_t	dst_size;
	size_t	src_size;

	dst_size = 0;
	src_size = 0;
	if (size == 0)
		return (dst_size + src_size + ft_strlen(src));
	while (dst[dst_size] != '\0' && dst_size < size)
		dst_size++;
	while (src[src_size] != '\0' && (dst_size + src_size + 1) < size)
	{
		dst[dst_size + src_size] = src[src_size];
		src_size++;
	}
	if (dst_size < size)
		dst[dst_size + src_size] = '\0';
	return (dst_size + ft_strlen(src));
}

// int	main(void)
// {
// 	char	dst[] = "lorem ipsum dolor sit amet";
// 	char	dst2[] = "lorem ipsum dolor sit amet";
// 	char	src[] = "rrrrrrrrrrrrrrr";
// 	char	src2[] = "rrrrrrrrrrrrrrr";
// 	printf("Source: %s\n", src);
// 	printf("Source2: %s\n", src2);
// 	printf("Destination: %s\n", dst);
// 	printf("Destination2: %s\n", dst2);
// 	printf("Concatenated String Size: %zu\n", strlcat(dst, src, 5));
// 	printf("Concatenated String2 Size: %zu\n", ft_strlcat(dst2, src2, 5));
// 	printf("Concatenated String: %s\n", dst);
// 	printf("Concatenated String2: %s\n", dst2);
// 	return (0);
// }