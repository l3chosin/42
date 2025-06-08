#include "libftprintf.h"  
#include <stdio.h>
#include <limits.h>
int main(void)
{
    int len1, len2;
    void *ptr;

    // Test 1: String básico
    len1 = ft_printf("Mi printf: %s\n", "Hola mundo");
    len2 = printf("EL printf: %s\n", "Hola mundo");
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 2: Carácter básico
    len1 = ft_printf("Mi printf: %c\n", 'A');
    len2 = printf("EL printf: %c\n", 'A');
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 3: Entero básico
    len1 = ft_printf("Mi printf: %d\n", 42);
    len2 = printf("EL printf: %d\n", 42);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 4: Unsigned básico
    len1 = ft_printf("Mi printf: %u\n", 42000);
    len2 = printf("EL printf: %u\n", 42000);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 5: Puntero no nulo
    ptr = (void *)0x12345678;
    len1 = ft_printf("Mi printf: %p\n", ptr);
    len2 = printf("EL printf: %p\n", ptr);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 6: Hexadecimal (minúsculas) básico
    len1 = ft_printf("Mi printf: %x\n", 255);
    len2 = printf("EL printf: %x\n", 255);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 7: Hexadecimal (mayúsculas) básico
    len1 = ft_printf("Mi printf: %X\n", 255);
    len2 = printf("EL printf: %X\n", 255);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 8: Puntero nulo (se espera "(nil)" o el formato definido)
    len1 = ft_printf("Puntero nulo: %p\n", (void*)NULL);
    len2 = printf("Puntero nulo: %p\n", (void*)NULL);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 9: Puntero extremo
    ptr = (void*)0x7fffffffffffffff;
    len1 = ft_printf("Puntero extremo: %p\n", ptr);
    len2 = printf("Puntero extremo: %p\n", ptr);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 10: Cadena nula (se espera "(null)" o el formato definido)
    len1 = ft_printf("Cadena nula: %s\n", (char*)NULL);
    len2 = printf("Cadena nula: %s\n", (char*)NULL);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 11: Entero extremos (%d y %i)
    len1 = ft_printf("Entero mínimo: %d, Entero máximo: %i\n", INT_MIN, INT_MAX);
    len2 = printf("Entero mínimo: %d, Entero máximo: %i\n", INT_MIN, INT_MAX);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 12: Unsigned máximo
    len1 = ft_printf("Unsigned max: %u\n", 4294967295u);
    len2 = printf("Unsigned max: %u\n", 4294967295u);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 13: Hexadecimal extremos para %x y %X
    len1 = ft_printf("Hex minúsculas: %x, Hex mayúsculas: %X\n", 4294967295u, 4294967295u);
    len2 = printf("Hex minúsculas: %x, Hex mayúsculas: %X\n", 4294967295u, 4294967295u);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 14: Carácter NUL y caracter ordinario para %c
    len1 = ft_printf("Caracter NUL:[%c] y caracter ordinario: [%c]\n", '\0', 'A');
    len2 = printf("Caracter NUL:[%c] y caracter ordinario: [%c]\n", '\0', 'A');
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 15: Literal de porcentaje %%
    len1 = ft_printf("Porcentaje: %%\n");
    len2 = printf("Porcentaje: %%\n");
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 16: Mezcla de conversiones
    len1 = ft_printf("Mezcla: [%s] [%c] [%p] [%d] [%u] [%x] [%X] [%%]\n",
                     "TextoExtremo", 'X', (void*)NULL, -123456789, 987654321, 3735928559u, 3735928559u);
    len2 = printf("Mezcla: [%s] [%c] [%p] [%d] [%u] [%x] [%X] [%%]\n",
                  "TextoExtremo", 'X', (void*)NULL, -123456789, 987654321, 3735928559u, 3735928559u);
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 17: Especificadores adyacentes con cadena nula intercalada
    len1 = ft_printf("Concatenados: %s%s%s\n", "Inicio", (char*)NULL, "Final");
    len2 = printf("Concatenados: %s%s%s\n", "Inicio", (char*)NULL, "Final");
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    // Test 18: Ancho y precisión (%d y %s) 
    len1 = ft_printf("Ancho y precisión: %10.5d, %10.5s\n", 123, "pruebaextrema");
    len2 = printf("Ancho y precisión: %10.5d, %10.5s\n", 123, "pruebaextrema");
    printf("Len ft_printf: %d | Len printf: %d\n\n", len1, len2);

    return 0;
}

