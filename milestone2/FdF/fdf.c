#include "fdf.h"

int	main()
{
	mlx_t*	mlx;

	mlx = mlx_init(1920, 1080, "Ekisde", true);
	if (!mlx)
	{
		return EXIT_FAILURE;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return EXIT_SUCCESS;
}
