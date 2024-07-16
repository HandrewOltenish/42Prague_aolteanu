/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:29:06 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/04 22:12:31 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

#include "libft.h"

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*pointer_src;
	char			*pointer_dest;
	size_t			count;

	pointer_src = src;
	pointer_dest = dest;
	count = 0;
	while (count < n)
	{
		pointer_dest[count] = pointer_src[count];
		count++;
	}
	return (pointer_dest);
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	void *dest_ptr;

// 	dest_ptr = dest;
// 	if ((!dest && !src) || (dest == src))
// 		return (dest);
// 	if (dest > src)
// 	{
// 		while (n--)
// 			((char *)dest)[n] = ((char *)src)[n];
// 	}
// 	else
// 	{
// 		while (n--)
// 			*(char *)dest++ = *(char *)src++;
// 	}
// 	return (dest_ptr);
// }

// Same shit as this:
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;
	size_t		i;

	i = 0;
	p_dest = (char *)dest;
	p_src = (char *)src;
	if (p_dest > p_src)
	{
		while (n--)
			p_dest[n] = p_src[n];
	}
	else
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = {67, 68, 67, 68, 69, 0, 45};
//
// 	printf("String before moving bytes: %s\n", src);
// //	printf("Desired result: %s\n", src);
// 	ft_memmove(src + 1, src, 2);
// 	printf("String after moving bytes: %s\n", src);
// 	return (0);
// }
