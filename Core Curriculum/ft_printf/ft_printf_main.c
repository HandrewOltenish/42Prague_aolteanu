/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:48:12 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/12 23:46:30 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
   printf ("Characters: %c %c \n", 'a', 65);
//   printf ("Character error: %", "String");
   printf("Normal alignment of decimal: %d\n", 1.234);
   printf("Left-aligned adjustment of decimal: %-10d, %d, %d\n", 10, 11, 12);
   printf("Zero-padded value: %03d\n", 10);
//   printf("Zero-padded value with 0- flags: %0-3d\n", 10);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}