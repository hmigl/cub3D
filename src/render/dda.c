#include "cub3d.h"

void	cast_rays_using_dda(t_game *game)
{
	game->raycaster.hit = 0;
	while (!(game->raycaster.hit))
	{
		if (game->raycaster.side_dist.x < game->raycaster.side_dist.y)
		{
			game->raycaster.side_dist.x += game->raycaster.delta_dist.x;
			game->raycaster.map.x_i += game->raycaster.step.x_i;
			game->raycaster.side = 0;
		}
		else
		{
			game->raycaster.side_dist.y += game->raycaster.delta_dist.y;
			game->raycaster.map.y_i += game->raycaster.step.y_i;
			game->raycaster.side = 1;
		}
		if (game->scene->map.map_as_2d_array[game->raycaster.map.x_i][game->raycaster.map.y_i] == '1')
			game->raycaster.hit = 1;
	}
}

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
