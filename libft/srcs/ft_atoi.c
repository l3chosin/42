/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluther- <aluther-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:32:15 by aluther-          #+#    #+#             */
/*   Updated: 2025/05/12 12:23:11 by aluther-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    sign = 1;
    i = 0;
    result = 0;
    while (str[i] != '\0')
    {
        if (!((str[i] >= '0' && str[i] <= '9')||(str[i] == '-')||(str[i]=='+')))
            return (0);
        if ((str[i] == '-') && (str[i+1] >= '0') && (str[i+1] <= '9'))
            {
                sign = sign * -1;
                i++;
            }
        if ((str[i] == ' ')||(str[i] == '+')||(str[i]== '-'))
            {
                i++;
            }
        while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '\0'))
        {
            result = result * 10 + (str[i] - '0');
            i++;
        }
    }
    return (result * sign);
}

#include <stdio.h>
int main()
{
    int f;
    char str[] = "jajajekisde";

    f = ft_atoi(str);
    printf("Conversion to integer: %d", f);
    return (0);
}
