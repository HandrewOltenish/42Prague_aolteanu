/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:13:26 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/10 18:20:22 by aolteanu         ###   ########.fr       */
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

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	*ft_get_string(char *c, int length, int neg, int n)
{
	if (length == 0)
		c[length] = '0';
	else
	{
		while (n > 0 && length >= 0)
		{
			c[length + neg - 1] = n % 10 + '0';
			n = n / 10;
			length--;
		}
	}
	if (neg > 0)
		c[0] = '-';
	return (c);
}

static int	ft_numlength(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		length;
	int		negativity;

	length = ft_numlength(n);
	if (length == 0)
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		negativity = 1;
		c = (char *)malloc(sizeof(char) * (length + negativity + 1));
	}
	else if (n >= 0)
	{
		negativity = 0;
		c = (char *)malloc(sizeof(char) * (length + 1));
	}
	return (ft_get_string(c, length, negativity, n));
}

int	main(void)
{
	char	*c;
	int		n;

	n = -1234;
	c = ft_itoa(n);
	printf("Number: %i\nITOA: %s\n", n, c);
}
