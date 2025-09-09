
#include "libft/libft.h"
#include "push_swap.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_printf("Error! Utiliza el programa con:");
		ft_printf("./push_swap numero1 numero2 numero3 numero4 ...\n");
	}
	if (error == 2)
	{
		ft_printf("Se ha encontrado un argumento invalido en la posicion");
	}
}
