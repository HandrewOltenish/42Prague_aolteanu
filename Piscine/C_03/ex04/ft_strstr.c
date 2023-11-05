/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:09:01 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/05 16:56:39 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  strstr()  function finds the first occurrence of the substring needle
// in the string haystack.  The terminating null bytes ('\0') are not com‐
// pared.
// These functions return a pointer to the beginning of the located substring,
// or NULL if the substring is not found.

#include <unistd.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	remember;

	i = 0;
	j = 0;
	remember = 0;
	if (!str || !to_find)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			remember = str[i] - to_find[j];
			while (to_find[j] && remember == 0)
			{
				remember = remember + str[i + j] - to_find [j];
				j++;
			}
			if (remember == 0)
				return (&str[i]);
			else
				*(to_find + 0);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*str = "samusamusamurai";
	char	*to_find = "samurai";
	char	*s = ft_strstr(str, to_find);

	printf("String: %s\nTo Find: %s\nAddress if found: %p", str, to_find, s);
	return (0);
}