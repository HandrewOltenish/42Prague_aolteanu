/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolteanu <aolteanu.student@42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:56:32 by aolteanu          #+#    #+#             */
/*   Updated: 2023/10/16 16:52:25 by aolteanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_isalpha(int a)
{
if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
        return (a);
    else
        return (0);
}
// }
// int main()
// {
//     int a = '7';
//     printf("Your alphabetical character,sir: %d \n", (ft_isalpha(a)));
//     return 0;
// }