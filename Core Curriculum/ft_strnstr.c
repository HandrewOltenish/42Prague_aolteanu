/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:35:48 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/27 22:13:10 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//		The strnstr() function locates the first occurrence of the
//	null-terminated string little in the string big, where not more
//	than len characters are searched.  Characters that appear after
//	a ‘\0’ character are not searched.  Since the strnstr()function is a
//	FreeBSD specific API, it should only be used when portability is not
//	a concern.
//
//		If little is an empty string, big is returned; if little occurs
//	nowhere in big, NULL is returned; otherwise a pointer to the first
//	character of the first occurrence of little is returned.

#include <bsd/string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*pointer;
	char	*counter;
	int	index_little;
	int	index_big;

	index_little = 0;
	index_big = 0;

	while (big[index_big] != '\0' && little[index_little] != '\0' && len > 0)
	{
		if (little[index_little] == big[index_big])
		{
			counter = (char *)&big[index_big];
			index_little++;
		}
		index_big++;
		len--;
	}
	if (!little)
		return ((char *)big);
	if (*little != *big)
		return (NULL);
	else
		return ((char *)big);
}

int main()
{
	char	*big = "Biggus Dickus";
	char	*little = "Dick";
	size_t	len = 13;
	char	*big2 = "Biggus Dickus";
	char	*little2 = "Dick";
	size_t	len2 = 13;

	printf("Fellas is it gay to search a string?\n%s\n%s\n", big, little);
	printf("Searched upon %zu byte(s) and found this:\n%p\n", len, ft_strnstr(big, little, len));
	printf("Fellas is it gay to search a string?\n%s\n%s\n", big2, little2);
	printf("Searched upon %zu byte(s) and found this:\n%p\n", len2, strnstr(big2, little2, len2));
	return (0);
}