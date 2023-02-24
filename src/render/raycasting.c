#include "cub3d.h"

static void	calc_next_step_and_cast_rays(t_game *game)
{
	calc_next_step(game);
	cast_rays_using_dda(game);
}

static void	set_raycaster_data(t_game *game, int x)
{
	game->raycaster.camera.x = 2 * x / (double) WIN_WIDTH - 1;
	game->raycaster.ray_dir.x = game->direction.x
		+ game->plane.x * game->raycaster.camera.x;
	game->raycaster.ray_dir.y = game->direction.y
		+ game->plane.y * game->raycaster.camera.x;
	game->raycaster.map.x_i = (int) game->player.x;
	game->raycaster.map.y_i = (int) game->player.y;
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
		calc_next_step_and_cast_rays(game);
	}
}
