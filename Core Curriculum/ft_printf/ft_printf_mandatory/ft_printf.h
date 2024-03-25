/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:21:24 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/25 19:41:34 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
 #define FT_PRINTF_H
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <limits.h>

typedef struct list_node
{
	void				*content;
	struct list_node	*next;
}	node;

// ft_printf returns the number of characters printed.
int ft_printf(const char *format, ...);
// ft_revstr returns reversed string.
char *ft_revstr(char *s, char *revstr);
// ft_charlen returns the length of a char
int ft_charlen(int number);
// ft_strlen returns the length of a string
int ft_strlen(char	*str);
// ft_plen returns the length of a pointer
int ft_plen(void *p);
// ft_pint casts void *p into size_t for arithmetic operations
int ft_pint(size_t p);
// ft_dlen returns length of a base 10 integer
int ft_dorilen(int number);
// ft_ulen returns length of unsigned decimal
int ft_ulen(unsigned int);
// ft_xXlen returns length of number in base 16 lowercase (x) or uppercase (X)
int ft_xXlen(char format, int number);
// ft_pcentlen returns lengrh of number in base 16 uppercase ( can be the same as ft_clen)
int ft_pcentlen(void);
// ft_zerolen returns length of number padded with n number of zeroes to the left
int ft_zerolen(int number, int atoi);
// ft_dashlen left-side justifies decimal with n number of spaces
int ft_dashlen(int number, int n);
// ft_hashlen returns length of x or X addresses, precedented by 0x or 0X for values diffrent than zero. ft_xlen & ft_Xlen can be used instad. Needs checking.
int ft_hashlen(int number, int format);
// ft_spacelen returns length of value preceded by blank space if no sign is written
int ft_spacelen(int number);
#endif