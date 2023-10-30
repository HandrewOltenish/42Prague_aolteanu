/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:31:06 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/27 16:14:11 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	memchr, memrchr, rawmemchr - scan memory for a character
//		The  memchr() function scans the initial n bytes of the memory area
//	pointed to by s for the first instance of c.  Both c and the bytes of
//	the memory area pointed to by s are interpreted as unsigned char.
//		The memchr() and memrchr() functions return a pointer to the
//	matching byte or NULL if the character does not occur in the given
//	memory area.

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*pointer_s;
	unsigned char		instance_c;
	int					byte_n;

	pointer_s = s;
	instance_c = c;
	byte_n = n;
	while (*pointer_s != '\0' && byte_n > 0 && *pointer_s != instance_c)
	{
		pointer_s++;
		byte_n--;
	}
	if (*pointer_s == instance_c)
		return ((void *)pointer_s);
	else
		return (NULL);
}

// int main()
// {
// 	char *s = "D eez nutz";
// 	int	c = 'D';
// 	size_t	n = 6;
// 	char *s2 = "D eez nutz";
// 	int	c2 = 'D';
// 	size_t	n2 = 6;
// 	printf("Find %c in %s\nDid ya find it, pal?
//\n It's at %p\n", c, s, memchr(s, c, n));
// 	printf("Find %c in %s\nDid ya find it, pal?
//\n It's at %p\n", c2, s2, ft_memchr(s2, c2, n2));
// }