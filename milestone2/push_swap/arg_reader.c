/* Esta parte del programa tiene como objetivo leer
los argumentos introducidos al programa, comprobar
si se trata de argumentos validos,
crear nodos donde guardar los valores ordenados
para tener el stack a con todos los valores necesarios
para poder ordenarlos. */

#include "push_swap.h"

static int arg_checker(char *number, int *ok)
{
	int	n;

	n = ft_atoi_ok(number, ok);
	return (n);
}

int	*arg_reader(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*stack;
	int	ok;

	i = 1;
	j = 0;
	if (argc < 2)
		return (ft_error(1), NULL);
	stack = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		stack[j] = arg_checker(argv[i], &ok);
		if (ok == 0)
			return (ft_error(2), ft_printf("%d\n", i), free(stack), NULL);
		i++;
		j++;
	}
	return (ft_printf("Los datos son validos!"), stack);
}
