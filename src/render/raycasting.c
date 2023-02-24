#include "cub3d.h"

static void	calc_next_step_and_cast_rays(t_game *game)
{
	calc_next_step(game);
	cast_rays_using_dda(game);
}

static void	set_raycaster_data(t_game *game, int x)
{
	game->rc.camera.x = 2 * x / (double) WIN_WIDTH - 1;
	game->rc.ray_dir.x = game->dir.x + game->plane.x * game->rc.camera.x;
	game->rc.ray_dir.y = game->dir.y + game->plane.y * game->rc.camera.x;
	game->rc.map.x_i = (int) game->player.x;
	game->rc.map.y_i = (int) game->player.y;
	game->rc.delta_dist.x = fabs(1 / game->rc.ray_dir.x);
	game->rc.delta_dist.y = fabs(1 / game->rc.ray_dir.y);
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
