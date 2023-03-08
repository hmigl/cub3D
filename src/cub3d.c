#include "cub3d.h"

static void	pre_raycasting_setup(t_game *game)
{
	game->player.pos.x = game->scene->map.x_start_pos + 0.5;
	game->player.pos.y = game->scene->map.y_start_pos + 0.5;
	vectors_setup(game);
	mlx_setup(game);
	position_setup(game, get_radians(game));
	textures_setup(game);
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
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
