/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:21:24 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/16 17:57:25 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_printf_revstr(char *s, char *revstr);
int		ft_printf_strsize(char *s);
int		ft_printf_putstr(char	*s);
int		ft_printf(const char *format, ...);
int		ft_printf_charlen(int number);
int		ft_printf_strlen(char	*str);
int		ft_plen(void *p);
int		ft_pint(size_t p);
int		ft_dorilen(int number);
int		ft_ulen(unsigned int number);
int		ft_xxlen(char format, unsigned int number);
#endif
