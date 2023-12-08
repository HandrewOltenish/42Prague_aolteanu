/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:23:07 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/05 12:21:51 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <bsd/string.h>

//The strlcpy() function copies up to size - 1 characters from the NUL-ter‐
//minated string src to dst, NUL-terminating the result.
// compile it like this "cc -libbsd ft_strlcpy.c"

#include "libft.h"

// size_t	ft_strlcpy(char	*dst,	const char	*src, size_t	size)
// {
// 	char		*pointer_dst;
// 	const char	*pointer_src;
// 	size_t		count;

// 	count = 0;
// 	pointer_dst = dst;
// 	pointer_src = src;
// 	if (pointer_src != 0)
// 	{
// 		while (count < size && size > 0 && pointer_src[count] != '\0')
// 		{
// 			pointer_dst[count] = pointer_src[count];
// 			count++;
// 		}
// 		while (pointer_dst[count] != '\0')
// 		{
// 			count++;
// 		}
// 		pointer_dst[count] = '\0';
// 	}
// 	return (count);
// }

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

// int	main(void)
// {
// 	char	src1[] = "Uspide Down!";
// 	char	dst1[50] = "Downside Up!";
// 	char	src2[] = "Uspide Down!";
// 	char	dst2[50] = "Downside Up!";
// 	size_t	r1;
// 	size_t	r2;
// 	//printf("%s\n", dst);
// 	r1 = strlcpy(dst1, src1, 20);
// 	r2 = ft_strlcpy(dst2, src2, 20);
// 	printf("%s, Bytes copied %zu\n", dst1, r1);
// 	printf("%s, Bytes copied %zu\n", dst2, r2);
// 	return (0);
// }
