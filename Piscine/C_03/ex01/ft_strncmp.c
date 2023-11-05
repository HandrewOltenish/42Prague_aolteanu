/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:57:51 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/05 14:12:15 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Reproduce the behavior of the function strncmp (man strncmp).
• Here’s how it should be prototyped :
int ft_strncmp(char *s1, char *s2, unsigned int n);
*/
#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)

{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (!value && (s1[i] || s2[i]) && i < n)
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
/*
int	main(void)

{
	printf("Who is bigger?\nIf s1 > s2 type 1\n");
	printf("If s1 < s2 type -1\n");
	printf("If s1 == s2 type 0\n");
	printf("Let's see the result: %i\n", ft_strncmp("Bingus", "Bongus", 5));
	printf("Let's see the result: %i\n", strncmp("Bingus", "Bongus", 5));
	return (0);
}
*/
