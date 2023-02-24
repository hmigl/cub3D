#include "cub3d.h"

static void	setup_camera_plane(t_game *game)
{
	game->plane.x = 0;
	game->plane.y = 0.66;
}

static void	setup_facing_direction(t_game *game)
{
	game->direction.x = -1;
	game->direction.y = 0;
}

void	vectors_setup(t_game *game)
{
	setup_facing_direction(game);
	setup_camera_plane(game);
}
