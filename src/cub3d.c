#include "cub3d.h"

#define USAGE "usage: ./cub3d FILE.cub\n"

void	display_usage_and_exit(void)
{
	write(STDERR_FILENO, USAGE, ft_strlen(USAGE));
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		display_usage_and_exit();
	parse_map(&map, argv[1]);
	return (0);
}
