/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:57:29 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/01 18:18:02 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//		The bzero() function erases the data in the n bytes of the memory
//	starting at the location pointed to by s, by writing zeros (bytes
//	containing '\0') to that area.

#include <stdio.h>
#include <strings.h>
#include <unistd.h>

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

// int	main(void)
// {
// 	char	s[] = "trololol";
// 	printf("%s BEGONE, STRING!\n", s);
// //	bzero(s, 7);
// 	ft_bzero(s, 7);
// 	printf("%s POOF\n", s);
// }