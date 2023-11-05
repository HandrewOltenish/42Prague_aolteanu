/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:05:48 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/05 16:23:50 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_len(char *str)
{	
	int	i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *str_1, char *str_2, int n)
{
	int	i;
	i = 0;
	while (str_1[i] && str_1[i] == str_2[i] && (i < n - 1))
		i++;
	return (str_1[i] - str_2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	n;
	n = ft_str_len(to_find);
	if (n == 0)
		return (str);
	while (*str)
	{
		if (ft_strncmp(str, to_find, n) == 0)
			return (str);
		str++;
	}
	return (NULL);
}

int	main()
{
	char	*str = "Andrei is great";
	char	*to_find = "is";
	char	*s = ft_strstr(str, to_find);

	printf("String: %s\nTo Copy: %s\nResult: %s\n", str, to_find, s);
	return (0);
}