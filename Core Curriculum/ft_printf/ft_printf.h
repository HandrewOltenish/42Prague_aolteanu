/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:50:14 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/11 17:13:16 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
 #define FT_PRINTF_H
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>

typedef struct list_node
{
	void				*content;
	struct list_node	*next;
}	node;
// ft_charlen returns the length of a char
int ft_clen(int number);
// ft_strlen returns the length of a string
int ft_slen(char	*str);
// ft_plen returns the length of a pointer
int ft_plen(void *p);
// ft_dlen returns length of a base 10 integer
int ft_dlen(int number);
// ft_ulen returns length of unsigned decimal
int ft_ulen(unsigned int);
// ft_xlen returns length of number in base 16 lowercase
int ft_xlen(int number);
// ft_Xlen returns length of number in base 16 uppercase
int ft_Xlen(int number);
// ft_pcentlen returns lengrh of number in base 16 uppercase ( can be the same as ft_clen)
int ft_pcentlen(int number);
// ft_zerolen returns length of number padded with n number of zeroes to the left
int ft_zerolen(int number);
// ft_dashlen left-side justifies decimal with n number of spaces
int ft_dashlen(int number);
// ft_hashlen returns length of x or X addresses, precedented by 0x or 0X for values diffrent than zero
// ft_xlen & ft_Xlen can be used instad. Needs checking.
int ft_hashlen(int number);
// ft_spacelen returns length of value preceded by blank space if no sign is written
int ft_spacelen(int number);
#endif