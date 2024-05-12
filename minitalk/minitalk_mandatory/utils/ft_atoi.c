/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:38:13 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/06 19:15:27 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int		number;
	short	sign;

	number = 0;
	sign = 1;
	if (nptr == NULL)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if ((*nptr++) == '-')
			sign = -1;
	while ('0' <= *nptr && *nptr <= '9')
		number = (number * 10) + ((*nptr++) - '0');
	return (number * sign);
}
