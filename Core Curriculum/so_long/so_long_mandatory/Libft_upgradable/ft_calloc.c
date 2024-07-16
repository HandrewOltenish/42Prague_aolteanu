/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:19:51 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/10 16:52:54 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The calloc() function allocates memory for an array of nmemb elements
//of size bytes each and returns a  pointer  to  the  allocatedmemory.
//The  memory is set to zero.  If nmemb or size is 0, then calloc()
//returns either NULL, or a unique pointer value that can later be
//successfully passed to free().  If the multiplication of nmemb
//and size would result in integer  overflow,  then  calloc()
//returns  an  error.  By contrast, an integer overflow would
//not be detected in the following call to malloc(), with
//the result that an incorrectly sized block of memory would be allocated:
//
//	malloc(nmemb * size);
//
//The malloc() and calloc() functions return a pointer to the allocated
//memory, which is suitably aligned for any built-in type.
//On error,  these  functions return NULL.  NULL may also be returned
// by a successful call to malloc() with a size of zero, or by a suc‐
//cessful call to calloc() with nmemb or size equal to zero.
//
// #include <stdlib.h>
// #include <stdio.h>

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*pointer_alpha;
	size_t			count;

	pointer_alpha = s;
	count = 0;
	while (count < n)
	{
		pointer_alpha[count] = '\0';
		count++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;

	p = NULL;
	if (nmemb == 0 || size == 0)
	{
		p = (unsigned char *)malloc(0);
		return (p);
	}
	if (nmemb * size / size != nmemb)
		return (NULL);
	p = (unsigned char *)malloc(nmemb * size);
	if (!p)
		return (p);
	ft_bzero(p, (nmemb * size));
	return (p);
}

// int main()
// {
// 	char e[] = {0, 0, 0, 0};
// 	printf("This is the pointer "
// 	"to address allocated by calloc:%p\n", calloc(2, 2));
// 	printf("This is the pointer "
// 	"to address allocated by calloc:%p\n", ft_calloc(2, 2));
// 	printf("Memcmp: %i\n", memcmp(calloc(2, 2), e, 4));
// 	printf("Memcmp: %i\n", memcmp(ft_calloc(2, 2), e, 4));
// 	free(calloc(2, 2));
// 	free(ft_calloc(2, 2));
// 	return (0);
// }