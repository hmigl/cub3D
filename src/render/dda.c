#include "cub3d.h"

void	cast_rays_using_dda(t_game *game)
{
	char	**aux;

	game->rc.hit = 0;
	while (!(game->rc.hit))
	{
		if (game->rc.side_dist.x < game->rc.side_dist.y)
		{
			game->rc.side_dist.x += game->rc.delta_dist.x;
			game->rc.map.x_i += game->rc.step.x_i;
			game->rc.side = 0;
		}
		else
		{
			game->rc.side_dist.y += game->rc.delta_dist.y;
			game->rc.map.y_i += game->rc.step.y_i;
			game->rc.side = 1;
		}
		aux = game->scene->map.map_as_2d_array;
		if (aux[game->rc.map.x_i][game->rc.map.y_i] == WALL)
			game->rc.hit = 1;
	}
}

void	calc_next_step(t_game *game)
{
	if (game->rc.ray_dir.x < 0)
	{
		game->rc.step.x_i = -1;
		game->rc.side_dist.x = (game->player.pos.x - game->rc.map.x_i)
			* game->rc.delta_dist.x;
	}
	else
	{
		game->rc.step.x_i = 1;
		game->rc.side_dist.x = (game->rc.map.x_i + 1.0 - game->player.pos.x)
			* game->rc.delta_dist.x;
	}
	if (game->rc.ray_dir.y < 0)
	{
		game->rc.step.y_i = -1;
		game->rc.side_dist.y = (game->player.pos.y - game->rc.map.y_i)
			* game->rc.delta_dist.y;
	}
	else
	{
		game->rc.step.y_i = 1;
		game->rc.side_dist.y = (game->rc.map.y_i + 1.0 - game->player.pos.y)
			* game->rc.delta_dist.y;
	}
}
