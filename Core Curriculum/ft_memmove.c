/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:29:06 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/27 16:14:42 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void	*dest, const void	*src, size_t	n)
{
	char			*pointer_dest;
	const char		*pointer_src;
	size_t			count;

	pointer_dest = dest;
	pointer_src = src;
	count = 0;
	if (pointer_src <= pointer_dest)
	{
		while (count < n)
		{
			pointer_dest[count] = pointer_src[count];
			count++;
		}
	}
	else if (n <= sizeof(pointer_dest))
	{
		while (count < n)
		{
			pointer_dest[count] = pointer_src[count];
			count++;
		}
	}
	return (pointer_dest);
}

// int	main(void)
// {
// 	char	src[] = "Le fabuleux destin d'";
//     char	dest[] = "Amelie Poulain";

// 	printf("String before moving bytes: %s\n", src);
// 	ft_memmove(src + 21, dest, 14);
// 	printf("String after moving bytes: %s\n", src);
// 	return (0);
// }