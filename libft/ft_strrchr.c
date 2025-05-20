/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:36:59 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/18 22:37:01 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrchr(char *str, int c)
{
    int i = 0;
    int j = -1; // Usamos -1 para indicar que no se encontró aún.

    while (str[i])
    {
        if (str[i] == c)
            j = i;
        i++;
    }

    if (j != -1)
        return (&str[j]);

    return (0);
}

#include <stdio.h>

/*int main()
{
    char str[] = "Gordas tatasss";
    int c = 'a';
    char *result;

    result = ft_strrchr(str, c);

    if (result)
        printf("Ultima aparicion de caracter encontrada en %p, caracter: %c\n", (void*)result, *result);
    else
        printf("No se ha encontrado el caracter\n");

    return 0;
    }*/
