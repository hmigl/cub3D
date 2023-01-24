#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		display_error_msg_and_exit(WRONG_USAGE);
	parse_map(&map, argv[1]);
	return (0);
}
