/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:53:59 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/30 10:27:04 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int d)
{
	if (48 >= d && d <= 57)
		return (d);
	else
		return (0);
}
int	main()
{
	int d = 9;
	printf("Here is your digit: %d", ft_isdigit(d));
	printf("Here is your digit: %d", isdigit(d));
	return 0;
}