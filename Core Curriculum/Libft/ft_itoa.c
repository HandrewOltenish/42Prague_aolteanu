/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:13:26 by aolteanu          #+#    #+#             */
/*   Updated: 2023/12/08 21:06:35 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_itoa
// Prototype char *ft_itoa(int n);
// Turn in files -
// Parameters n: the integer to convert.
// Return value The string representing the integer.
// NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.

// !

// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>

#include "libft.h"

static int	ft_numlength(int n)
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

// int	main(void)
// {
// 	char	*string;
// 	int		n;

// 	n = INT_MIN;
// 	string = ft_itoa(n);
// 	printf("Number: %i\nITOA: %s\n", n, string);
// }
