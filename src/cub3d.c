#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		return (1);
	parse_map(&map, argv[1]);
	return (0);
}
