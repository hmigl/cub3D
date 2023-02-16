#include "cub3d.h"

static void	pre_raycasting_setup(t_game *game)
{
	mlx_setup(game);
}

int	main(int argc, char *argv[])
{
	t_scene_desc	scene;
	t_game			game;

	if (argc != 2)
		display_error_msg_and_exit(WRONG_USAGE);
	ft_bzero(&scene, sizeof(t_scene_desc));
	parse_scene_desc(&scene, argv[1]);
	game.scene = &scene;
	pre_raycasting_setup(&game);
	// init_window(&game);
	return (0);
}
