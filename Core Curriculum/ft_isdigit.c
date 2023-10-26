/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:53:59 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/26 13:06:21 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int d)
{
	if (30 >= d <= 39)
		return (d);
	else
		return (0);
}
// int	main()
// {
// 	int d = 10;
// 	printf("Here is your digit: %d", ft_isdigit(d));
// 	return 0;
// }