/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:06:20 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/09 22:13:15 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main()
// {
// 	const char *s = "Skibbidi bop mm dada";
// 	printf("How many characters? =>%lu \n", strlen("Skibbidi bop mm dada"));
// 	printf("How many characters? =>%lu \n", ft_strlen("Skibbidi bop mm dada"));
// 	return (0);
// }