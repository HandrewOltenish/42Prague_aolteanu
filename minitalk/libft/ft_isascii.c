/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:53:37 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/02 18:38:54 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

#include "libft.h"

int	ft_isascii(int a)
{
	return ((0 <= a) && (127 >= a));
}

// int	main()
// {
// 	printf("What are you ASCIIng about? %d", ft_isascii(0));
// 	return (0);
// }