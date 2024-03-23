/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:48:12 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/23 16:32:24 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
   printf("Characters: %c %c \n", 'a', 65);
   // ft_printf("Characters: %c %c \n", 'a', 65);
   printf("Handling space format% d, % d\n", 10, -10);
//   printf ("Character error: %", "String");
  printf("Normal alignment of decimal: %d\n", 1234);
   printf("Precision: Minimum number of characters to be printed: %.10d\n", 12345);
   printf("Left-aligned adjustment of decimal: %-10d, %d, %d\n", 10, 11, 12);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", -10);
   printf ("Preceding with zeros: %010d \n", -10);
   printf ("Width and precision: %10.10d\n", 123123);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("%s \n", "A string");
   return (0);
}