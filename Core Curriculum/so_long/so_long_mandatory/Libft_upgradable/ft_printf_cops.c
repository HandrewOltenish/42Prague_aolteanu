/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:00:54 by aolteanu          #+#    #+#             */
/*   Updated: 2024/05/16 17:58:11 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putstr(char	*s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		len = len + ft_printf_charlen(s[i]);
		i++;
	}
	return (len);
}

int	ft_printf_strsize(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_printf_revstr(char *s, char *revstr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	while (i >= 0)
	{
		revstr[j] = s[i];
		i--;
		j++;
	}
	revstr[j] = '\0';
	return (revstr);
}

int	ft_printf_charlen(int c)
{
	return (write(1, &c, 1));
}
