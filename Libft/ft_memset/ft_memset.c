/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:25:16 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/18 17:11:20 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		// //Norm OK!
		// (unsigned char)*s[count++] = (unsigned char)c;
		// //vs Norm OK!
		// (unsigned char)*s;
		// (unsigned char)c;
		// s[count] = c;
		// count++;
		// //vs Norm Error! Variable declared in incorrect scope
		// unsigned char	*s;
		// unsigned char	c;
		// s[count] = c;
		// count++;
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t p)
{
	unsigned char	*pointer_alpha;
	size_t			count;

	pointer_alpha = s;
	count = 0;
	while (count < p)
	{
		pointer_alpha[count] = c;
		count++;
	}
	return (pointer_alpha);
}

int	main(void)
{
	char	str[] = "BreeJack";

	ft_memset(str, 'F', 1);
	printf("%s", str);
	return (0);
}
