/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:25:29 by marvin            #+#    #+#             */
/*   Updated: 2023/10/25 14:25:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//toupper, tolower - convert letter to upper or lower case

// #include <ctype.h>
// #include <stdio.h>

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	character;

	character = c;
	if (65 <= c && c <= 90)
	{
		character = character + 32;
	}
	else
		return (c);
	return (character);
}

// int main(void)
// {
//     int c;
//     c = 69;
//     printf("Original Character:%c\n", c);
//     printf("Lowercase Character:%c\n", ft_tolower(c));
//     return (0);
// }