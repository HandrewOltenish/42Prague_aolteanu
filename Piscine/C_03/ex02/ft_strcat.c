/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:47:06 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/05 15:08:05 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Reproduce the behavior of the function strcat (man strcat).
• Here’s how it should be prototyped :
char *ft_strcat(char *dest, char *src);
*/
#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (dest[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

// int	main()
// {
// 	char	dest[17] = "It is ";
// 	char	*src = "What it is";
// 	char	*s = ft_strcat(dest, src);

// 	printf("Destination: %s\nSource: %s\nConcatenation: %s\n", dest, src, s);
// 	return (0);
// }