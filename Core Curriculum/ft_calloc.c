/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:19:51 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/30 14:55:36 by aolteanu         ###   ########.fr       */
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

//	malloc(nmemb * size);

//The malloc() and calloc() functions return a pointer to the allocated
//memory, which is suitably aligned for any built-in type.
//On error,  these  functions return NULL.  NULL may also be returned
// by a successful call to malloc() with a size of zero, or by a suc‐
//cessful call to calloc() with nmemb or size equal to zero.

#include <stdlib.h>
#include <stdio.h>
//void *malloc (size_t size)
//void *calloc(size_t nmemb, size_t size)

int main()
{
	printf("This is the pointer to address allocated by calloc:%p", calloc(2, 10));
	return (0);
}