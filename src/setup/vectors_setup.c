#include "cub3d.h"

static void	setup_camera_plane(t_game *game)
{
	game->player.plane.x = 0;
	game->player.plane.y = 0.66;
}

static void	setup_facing_direction(t_game *game)
{
	game->player.dir.x = -1;
	game->player.dir.y = 0;
}

void	vectors_setup(t_game *game)
{
	setup_facing_direction(game);
	setup_camera_plane(game);
}
