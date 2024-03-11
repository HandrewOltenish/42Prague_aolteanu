/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:35:48 by aolteanu          #+#    #+#             */
/*   Updated: 2024/03/11 17:13:15 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ------------------------FORMAT HANDLING FUNCTIONS------------------------
void ft_handlechar(int number)
{
	char c;

	c = number;
	write (1, &c, 1);
}

void ft_handleformat(char format, va_list arg)
{
	if (format == 'c')
		ft_handlechar(va_arg(arg, int));
	if (format == 's')
		ft_handlestr(va_arg(arg, char	*));
	if (format == 'p')
		return (ft_handlep(va_arg(arg, void *)));
	if (format == 'd')
		ft_handled(va_arg(arg, int));
// return length of integer in base 10. Maybe same function, dlen.
	if (format == 'i')
		ft_handled(va_arg(arg, int));
	if (format == 'u')
		ft_handleu(va_arg(arg, unsigned int));
	if (format == 'x')
		ft_handlex(va_arg(arg, int));
	if (format == 'X')
		return (ft_Xlen(va_arg(arg, int)));
	if (format == '%')
      return (ft_pcentlen(va_arg(arg, int)));
   // bonus
   if (format == '0')
   {
      if (format++ == '-')
      {
         write(1, "flag '0' is ignored when flag '-' is present", 50);
         return (1);        
      }
      else return (ft_zerolen(va_arg(arg, int)));
   }
   if (format == '-')
   {
      if (format++ == '0')
      {
         write(1, "flag '0' is ignored when flag '-' is present", 50);
         return (1);        
      }
      else return (ft_dashlen(va_arg(arg, int)));
   }
   // Return xlen / Xlen + 2 from the 0x and 0X characters prefixed to them;
	if (format == '#')
   {
      if (format++ == 'x' && va_arg(arg, int) != 0)
         return (ft_xlen(va_arg(arg, int) + 2));
      else if (format++ == 'X' && va_arg(arg, int) != 0)
         return (ft_Xlen(va_arg(arg, int) + 2));
   }
	if (format == ' ')
	return (0);
}
// -----------------------------LENTGTH FUNCTIONS-----------------------------
// ft_charlen returns the length of a char
int ft_clen(int number)
{
	int i;
	return (i = 1);
}
// ft_strlen returns the length of a string
int ft_slen(char	*str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
// ft_plen returns the length of a pointer
int ft_plen(void *p)
{
	int i;

	i = 0;
	while ((char *)p++)
		i++;
	return (i);
}
// ft_dlen returns length of a base 10 integer
int ft_dlen(int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (i);
	while (number)
	{
		if (number < 0)
		{
			number = number * (-1);
			i++;
		}
		number = number / 10;
		i++;
	}
	return (i);
}
// ft_ulen returns length of unsigned decimal
int ft_ulen(unsigned int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (i);
	while (number)
	{
		number = number / 10;
		i++;
	}
	return (i);
}
// ft_xlen returns length of number in base 16 lowercase
int ft_xlen(int number)
{
	int i;
	char	*s;

	s = (char *)number;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
// ft_Xlen returns length of number in base 16 uppercase
int ft_Xlen(int number)
{
	int i;
	char	*s;

	s = (char *)number;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
// ft_pcentlen returns lengrh of number in base 16 uppercase ( can be the same as ft_clen)
int ft_pcentlen(int number)
{
	int i;
	return (i = 1);
}
// ft_zerolen returns length of number padded with n number of zeroes to the left
int ft_zerolen(int number)
{
	int i;
	char	*s;

	s = (char *)number;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
// ft_dashlen left-side justifies decimal with n number of spaces
int ft_dashlen(int number)
{
	int i;
	char	*s;

	s = (char *)number;
	i = 0;
	while (s[i])
		i++;
	return (i);
}
// ft_hashlen returns length of x or X addresses, precedented by 0x or 0X for values diffrent than zero
// ft_xlen & ft_Xlen can be used instad. Needs checking.
int ft_hashlen(int number)
{
	return (0);
}
// ft_spacelen returns length of value preceded by blank space if no sign is written, hence i++;
int ft_spacelen(int number)
{
	int i;

	i = 0;
	if (number == 0)
		return (i);
	while (number)
	{
		number = number / 10;
		i++;
	}
	i++;
	return (i);
}