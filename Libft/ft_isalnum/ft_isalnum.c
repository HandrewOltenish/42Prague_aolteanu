/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:24:00 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/16 16:33:51 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int a)
{
	if ((a >= 30 && a <= 39) && (a >= 65 && a <= 90) && (a >= 97 && a <= 122))
		return (a);
	else
		return (0);
}

// int	main()
// {
// 	int	a = 'A';
// 	printf ("Alphanumeric character goes here => %d", ft_isalnum(a));
// 	return (0);
// }
