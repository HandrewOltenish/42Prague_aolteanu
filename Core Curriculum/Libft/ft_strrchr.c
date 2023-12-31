/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:57:01 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/04 22:16:27 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The strrchr() function returns a pointer to the last occurrence of
// the character c in the string s.
// The strchr() and strrchr() functions return a pointer to the matched
//character or NULL if the character  is  not  found.
//The  terminating null byte is considered part of the string, so that
//if c is specified as '\0', these functions return a
//pointer to the terminator.
// #include <string.h>
// #include <stdio.h>

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	char	*occurence;

	occurence = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			occurence = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (occurence);
}

// int main()
// {
//     int c = 'a';
//     int c2 = 'b';
//     char    s[10] = "Babababa";
//     char    s2[10] = "Lelalele";
//     printf("String1: %s\n", s);
// 	printf("String2: %s\n", s2);
//     printf("First Character to be found: %c\n", c);
// 	printf("Second Character to be found: %c\n", c2);
//     printf("Print address of last occurence"
// 			"if found or null:%p\n", strrchr(s, c));
//     printf("Print address of last occurence"
// 			"if found or null:%p\n", ft_strrchr(s2, c2));
//     return (0);
// }
// int main(){
// 	char *str = "hi how are you";
// 	char *str2 = "ffff dfs affa aa aprint this!";

// 	char *res;
// 	char *res_ref;
// 	res = ft_strrchr(str, 'y');
// 	res_ref = strrchr(str, 'y');
// 	printf("my res: %s\norg. lib res: %s\n",res,res_ref);
// 	res = ft_strrchr(str2, 'a');
// 	res_ref = strrchr(str2, 'a');
// 	printf("my res: %s\norg. lib res: %s\n",res,res_ref);
// 	return (0);
// }