/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:53:37 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/16 16:57:52 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (a);
	else
		return (0);
}

// int	main()
// {
// 	int	a = 'a';
// 	printf("What are you ASCIIng about? %d", ft_isascii(a));
// 	return 0;
// }