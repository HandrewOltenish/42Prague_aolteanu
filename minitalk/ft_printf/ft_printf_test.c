/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:09:44 by aolteanu          #+#    #+#             */
/*   Updated: 2024/04/30 15:32:43 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int i;
	int j;
	
	i = printf("Hello %s %s\n", "Friend", "GOOO");
	j = ft_printf("Hello %s %s\n", "Friend", "GOOO");
	printf("\n %i vs %i", i, j);
	return (0);
}

// int	main()
// {
// 	char *p;
// 	int i;
// 	int j;
// 	p = "Skibidi bop mm dada";
// 	printf("Characters: %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n", 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65);
// 	ft_printf("Characters: %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n", 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65, 'a', 65);
// 	printf ("%s\n%s\n", "A string", "");
// 	ft_printf ("%s\n%s\n", "A string", "");
// 	printf("Pointer address: %p\n", &p);
// 	ft_printf("Pointer address: %p\n", &p);
// 	printf("Decimal & Integer: %d %i\n", 12, -12);
// 	ft_printf("Decimal & Integer: %d %i\n", 12, -12);
// 	printf("Unsigned integer: %u %u\n", 0, 123456);
// 	ft_printf("Unsigned integer: %u %u\n", 0, 123456);
// 	i = printf("x & X: %x %X\n", 12345, 12345);
// 	j = ft_printf("x & X: %x %X\n", 12345, 12345);
// 	printf("i = %i\nj = %d\n", i, j);
// 	ft_printf("i = %i\nj = %d\n", i, j);
// 	printf("Percent sign: %%\n");
// 	ft_printf("Percent sign: %%\n");
// 	// printf("Percent sign with error: %%", %);
// 	fclose (stdout);
// 	i = printf("a\n");
// 	j = ft_printf("a\n");
// 	dprintf(2, "i = %i\nj = %d\n", i, j);
// 	return (0);
// }