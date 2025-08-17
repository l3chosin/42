#include "fdf.h"

void	print_map_array(t_node *map_array, int col, int row)
{
    int x, y;

    y = 0;
    while (y < row)
    {
        x = 0;
        while (x < col)
        {
            printf("Node[%d,%d]: z = %d, color = 0x%06X\n",
                   x, y,
                   map_array[y * col + x].z,
                   map_array[y * col + x].color);
            x++;
        }
        y++;
    }
}
