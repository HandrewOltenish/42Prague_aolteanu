/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:28 by aolteanu          #+#    #+#             */
/*   Updated: 2023/11/14 15:50:46 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_split
// Prototype char **ft_split(char const *s, char c);
// Turn in files -
// Parameters s: The string to be split.
// c: The delimiter character.
// Return value The array of new strings resulting from the split.
// NULL if the allocation fails.
// External functs. malloc, free
// Description Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must end
// with a NULL pointer.

ft_delimiter(char *s, int index char c)
{
	if (s[index] == c)
	{
		counter++;
		instance++;
	}
	
}

size_t	ft_strlcpy(char	*dst,	const char	*src, size_t	size)
{
	char		*pointer_dst;
	const char	*pointer_src;
	size_t		count;

	count = 0;
	pointer_dst = dst;
	pointer_src = src;
	if (pointer_src > 0)
	{
		while (count < size && pointer_dst[count] != '\0')
		{
			pointer_dst[count] = pointer_src[count];
			count++;
		}
		pointer_dst[count + 1] = '\0';
	}
	return (count);
}

**ft_split(char const *s, char c)
{
	char	**array;
	int	index2;
	int	index;
	int	string_number;
	int	instance;

	index2 = 0;
	index = 0;
	string_number = 0;
	instance = 0;
	if (!s)
		return (0);
	while(s[index] != '\0')
	{
		if (s[index] == c)
		{
			ft_strlcpy(array[string_number][index2], *s, (instance + 1));
			instance++;
		
		}
		s++;
	}
	return(0);
}