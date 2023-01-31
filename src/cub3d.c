#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_scene_desc	scene;

	if (argc != 2)
		display_error_msg_and_exit(WRONG_USAGE);
	parse_scene_desc(&scene, argv[1]);
	return (0);
}
