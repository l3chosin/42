#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("Línea: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
