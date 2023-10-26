/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:58:34 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/26 13:07:53 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int p)
{
	if (32 <= p <= 126)
		return (p);
	else
		return (0);
}

// int	main()
// {
// 	int	p = ' ';
// 	printf("Printable? Princhair! %d", ft_isprint(p));
// }
