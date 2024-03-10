/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:50:14 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/10 19:58:33 by aolteanu         ###   ########.fr       */
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
#endif