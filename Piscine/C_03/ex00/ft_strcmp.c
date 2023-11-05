/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:36:37 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/05 14:11:47 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//• Reproduce the behavior of the function strcmp (man strcmp).
//• Here’s how it should be prototyped :
//int ft_strcmp(char *s1, char *s2);
//
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)

{
	int		i;
	int		value;

	i = 0;
	value = 0;
	while (!value && (s1[i] || s2[i]))
	{
		value = s1[i] - s2[i];
		i++;
	}
	if (value > 0)
	{
		return (1);
	}
	if (value < 0)
	{
		return (-1);
	}
	else
		return (0);
}

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "Xi Phu";
	s2 = "Lao Zhu";
	printf("Show -1 if s1 < s2\n");
	printf("Show 0 if s1 == s2\n");
	printf("Show 1 if s1 > s2\n");
	printf("Result is %i\n", strcmp(s1, s2));
	printf("Result is %i\n", ft_strcmp(s1, s2));
	return (0);
}
