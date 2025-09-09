/* Esta parte del programa tiene como objetivo leer
los argumentos introducidos al programa, comprobar
si se trata de argumentos validos,
crear nodos donde guardar los valores ordenados
para tener el stack a con todos los valores necesarios
para poder ordenarlos. */

#include "push_swap.h"

static void	*arg_checker(char *number)
{
	int	n;

	n = ft_atoi(number);
	
}

int	*arg_reader(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc < 2)
		return (ft_error(1), NULL);
	while (i < argc)
	{
		if (arg_checker(argv[i]) == NULL)
			return (ft_error(2), ft_printf("%d\n", i), NULL);
		i++;
	}
	return (0);
}
