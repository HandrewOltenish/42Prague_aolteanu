/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:13:26 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/12 14:16:13 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_numlength(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * (-1);
		count++;
	}
	if (n == 0)
		return (count = 1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*string;
	long	number;
	int		index;

	string = 0;
	number = n;
	index = ft_numlength(n) - 1;
	string = (char *)malloc(sizeof(char) * (ft_numlength(n) + 1));
	if (string == 0)
		return (NULL);
	if (n == -2147483648)
		number = 2147483648;
	else if (number < 0)
		number = number * (-1);
	string[ft_numlength(n)] = '\0';
	while (index >= 0)
	{
		string[index] = (number % 10) + '0';
		number = number / 10;
		index--;
	}
	if (n < 0)
		string[0] = '-';
	return (string);
}
