/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:35:48 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/29 15:37:45 by aolteanu         ###   ########.fr       */
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
//
// We need a temp array where to put the found characters then compare
#include <bsd/string.h>
#include <stdio.h>

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	value;
	int	index;

	i = 0;
	value = 0;
	index = n;
	while (!value && (s1[i] || s2[i]) && i < index)
	{
		value = s1[i] - s2[i];
		i++;
	}
	if (value > 0)
	{
		return (1);
	}
	if (value < 0)
	{
		return (-1);
	}
	else
		return (0);
}

static size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  little_len;
    if ((!big || !little) && len == 0)
        return (NULL);
    little_len = ft_strlen((char *)little);
    if (little_len == 0)
        return ((char *)big);
    while (*big && len >= little_len)
    {
        if (*big == *little && ft_strncmp(big, little, little_len) == 0)
            return ((char *)big);
        big++;
        len--;
    }
    return (NULL);
}

// int main()
// {
// 	char	*big = "Biggus Dickus";
// 	char	*little = "Dick";
// 	size_t	len = 13;
// 	char	*big2 = "Biggus Dickus";
// 	char	*little2 = "Dick";
// 	size_t	len2 = 13;

// 	printf("Fellas is it gay to search a string?\n%s\n%s\n", big, little);
// 	printf("Searched upon %zu byte(s) and found this:\n%p\n", len, ft_strnstr(big, little, len));
// 	printf("Fellas is it gay to search a string?\n%s\n%s\n", big2, little2);
// 	printf("Searched upon %zu byte(s) and found this:\n%p\n", len2, strnstr(big2, little2, len2));
// 	return (0);
// }