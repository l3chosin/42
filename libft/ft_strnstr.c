/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:13:54 by aluther           #+#    #+#             */
/*   Updated: 2025/05/20 19:13:56 by aluther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char ft_strnstr(char *haystack, char *needle, int size)
{
    int i;
    int j;
    int needle_lenght;

    i = 0;
    j = 0;
    needle_lenght = ft_strlen(needle);
    while(i < size && needle_lenght < size && haystack[i] != '\0')
    {
        if(haystack[i] == needle[j])
        {
            j = 0;
            while(haystack[i] == needle[j] && j < needle_lenght)
            {
                j++;
                i++;
                if(needle[j] == '\0')
                    return(haystack[i - j]);
            }

        }
        i++;
    }
    return (0);
}

/*#include <stdio.h>
int main()
{
    char haystack[] = "Holasoy jose";
    char needle[] = "y jose";
    int size = 10;

    char p = ft_strnstr(haystack, needle, size);

    if(p == 0)
        printf("Coincidencia no encontrada");
    else
        printf("Coincidendia encontrada");
    return (0);
    }*/
