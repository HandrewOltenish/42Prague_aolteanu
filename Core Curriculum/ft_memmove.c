/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:21:40 by marvin            #+#    #+#             */
/*   Updated: 2023/10/20 22:21:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memmove() function copies n bytes from memory area src to
//        memory area dest.  The memory areas may overlap: copying takes
//        place as though the bytes in src are first copied into a
//        temporary array that does not overlap src or dest, and the bytes
//        are then copied from the temporary array to dest.

#include <stdio.h>
#include <string.h>

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *pointer_dest;
    unsigned const char *pointer_src;
    unsigned char *temp;
    size_t  count;

    temp = [n];
    pointer_dest = dest;
    pointer_src = src;
    count = 0;
    if (temp > src)
    return (0);
    else while(count < n)
    {
        temp[count] = pointer_src[count];
        count++;
    }
    if(temp > dest)
    return(0);
    else count = 0;
        while(temp <= dest && count < n)
        {
            pointer_dest[count] = temp[count];
            count ++;
        }
    return(dest);
}

int main(void)
{
    char    src[] = "test";
    char    dest[] = "alpha";
    char    src2[] = "test2";
    char    dest2[] = "beta";

    printf("Before memmove %s\n%s\n", src, dest);
    memmove(dest, src, 2);
    printf("After memmove %s\n%s\n", src, dest);
    printf("Before memmove %s\n%s\n", src2, dest2);
    ft_memmove(dest2, src2, 2);
    printf("After memmove %s\n%s\n", src2, dest2);
    return (0);
}