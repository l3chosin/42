#include "fdf.h"

int	main()
{
	void	*mlx;

	mlx = mlx_init(1920, 1080, "Ekisde", true);
	if (!mlx)
	{
		return 1;
	}
	mlx_loop(mlx);

	return 0;
}
