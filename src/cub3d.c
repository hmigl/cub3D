#include "cub3d.h"

static void	init_scene_desc_objects(t_scene_desc *scene)
{
	*scene = (t_scene_desc){
		.fd = -1,
		.floor_color = -1,
		.ceiling_color = -1,
		.no_texture = NULL,
		.so_texture = NULL,
		.we_texture = NULL,
		.ea_texture = NULL,
		.map = malloc(sizeof(t_scene_map))
	};
}

int	main(int argc, char *argv[])
{
	t_scene_desc	scene;

	if (argc != 2)
		display_error_msg_and_exit(WRONG_USAGE);
	init_scene_desc_objects(&scene);
	parse_scene_desc(&scene, argv[1]);
	return (0);
}
