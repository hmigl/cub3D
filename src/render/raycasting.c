#include "cub3d.h"

static void	set_wall_height(t_game *game)
{
	// printf("side_dist.x: %f, side_dist.y: %f, delta_dist.x: %f, delta_dist.y: %f\n", game->rc.side_dist.x, game->rc.side_dist.y, game->rc.delta_dist.x, game->rc.delta_dist.y);
	if (game->rc.side == 0)
		game->rc.perp_wall_dist = (game->rc.side_dist.x - game->rc.delta_dist.x);
	else
		game->rc.perp_wall_dist = (game->rc.side_dist.y - game->rc.delta_dist.y);
	game->rc.line_height = (int) (WIN_HEIGHT / game->rc.perp_wall_dist);
	game->rc.draw_start = -game->rc.line_height / 2 + WIN_HEIGHT / 2;
	if (game->rc.draw_start < 0)
		game->rc.draw_start = 0;
	game->rc.draw_end = game->rc.line_height / 2 + WIN_HEIGHT / 2;
	if (game->rc.draw_end >= WIN_HEIGHT)
		game->rc.draw_end = WIN_HEIGHT - 1;
	// printf("draw_start: %d, draw_end: %d, line_height: %d, perp_wall_dist: %f\n", game->rc.draw_start, game->rc.draw_end, game->rc.line_height, game->rc.perp_wall_dist);
}

static void	set_raycaster_data(t_game *game, int x)
{
	game->rc.camera.x = 2 * x / (double) WIN_WIDTH - 1;
	game->rc.ray_dir.x = game->dir.x + game->plane.x * game->rc.camera.x;
	game->rc.ray_dir.y = game->dir.y + game->plane.y * game->rc.camera.x;
	game->rc.map.x_i = (int) game->player.x;
	game->rc.map.y_i = (int) game->player.y;
	if (game->rc.ray_dir.x == 0)
		game->rc.delta_dist.x = 100000000;
	else
		game->rc.delta_dist.x = fabs(1 / game->rc.ray_dir.x);
	if (game->rc.ray_dir.y == 0)
		game->rc.delta_dist.y = 100000000;
	else
		game->rc.delta_dist.y = fabs(1 / game->rc.ray_dir.y);
}

void	raycast(t_game *game)
{
	int	x;

	x = -1;
	printf("player.x: %f, player.y: %f, dir.x: %f, dir.y: %f, plane.x: %f, plane.y: %f\n", game->player.x, game->player.y, game->dir.x, game->dir.y, game->plane.x, game->plane.y);
	while (++x < WIN_WIDTH)
	{
		set_raycaster_data(game, x);
		calc_next_step(game);
		cast_rays_using_dda(game);
		set_wall_height(game);
		insert_texture(game, x);
	}
}
