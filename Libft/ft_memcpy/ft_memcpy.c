/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:13:13 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/19 15:21:08 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const	char		*pointer_src;
	char				*pointer_dest;
	size_t	count;

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
//For ft_memcpy it doesn't show when it overflows.
int	main(void)
{
	char	src[] = "-99 Problems but memcpy ain't one";
	char	dest[8] = "--";

	ft_memcpy(dest, src, 10);
	printf("\n%s\n", dest);
	return (0);
}