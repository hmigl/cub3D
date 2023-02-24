#include "cub3d.h"

static void	set_raycaster_data(t_game *game, int x)
{
	game->raycaster.camera.x = 2 * x / (double) WIN_WIDTH - 1;
	game->raycaster.ray_dir.x = game->direction.x
		+ game->plane.x * game->raycaster.camera.x;
	game->raycaster.ray_dir.y = game->direction.y
		+ game->plane.y * game->raycaster.camera.x;
	game->raycaster.map_x = (int) game->player.x;
	game->raycaster.map_y = (int) game->player.y;
	game->raycaster.delta_dist.x = fabs(1 / game->raycaster.ray_dir.x);
	game->raycaster.delta_dist.y = fabs(1 / game->raycaster.ray_dir.y);
}

void	raycast(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		set_raycaster_data(game, x);
	}
}
