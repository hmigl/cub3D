#include "cub3d.h"

void	calc_next_step(t_game *game)
{
	if (game->raycaster.ray_dir.x < 0)
	{
		game->raycaster.step.x_i = -1;
		game->raycaster.side_dist.x
			= (game->player.x - game->raycaster.map.x_i)
			* game->raycaster.delta_dist.x;
	}
	else
	{
		game->raycaster.step.x_i = 1;
		game->raycaster.side_dist.x
			= (game->raycaster.map.x_i + 1.0 - game->player.x)
			* game->raycaster.delta_dist.x;
	}
	if (game->raycaster.ray_dir.y < 0)
	{
		game->raycaster.step.x_i = -1;
		game->raycaster.side_dist.y
			= (game->player.y - game->raycaster.map.y_i)
			* game->raycaster.delta_dist.y;
	}
	else
	{
		game->raycaster.step.y_i = 1;
		game->raycaster.side_dist.y
			= (game->raycaster.map.y_i + 1.0 - game->player.y)
			* game->raycaster.delta_dist.y;
	}
}
