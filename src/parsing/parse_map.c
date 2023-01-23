#include "cub3d.h"

static int	open_map(const char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	return (fd);
}

void	parse_map(t_map *map, const char *filepath)
{
	map->fd = open_map(filepath);
}
