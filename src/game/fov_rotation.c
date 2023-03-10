#include "cub3d.h"

static void	rotate_right(t_game *game)
{
	t_vector	dir;
	t_vector	plane;

	dir = game->player.dir;
	plane = game->player.plane;
	game->player.dir.x = dir.x * cos(-game->player.rotation_speed)
		- dir.y * sin(-game->player.rotation_speed);
	game->player.dir.y = dir.x * sin(-game->player.rotation_speed)
		+ dir.y * cos(-game->player.rotation_speed);
	game->player.plane.x = plane.x * cos(-game->player.rotation_speed)
		- plane.y * sin(-game->player.rotation_speed);
	game->player.plane.y = plane.x * sin(-game->player.rotation_speed)
		+ plane.y * cos(-game->player.rotation_speed);
}

static void	rotate_left(t_game *game)
{
	t_vector	dir;
	t_vector	plane;

	dir = game->player.dir;
	plane = game->player.plane;
	game->player.dir.x = dir.x * cos(game->player.rotation_speed)
		- dir.y * sin(game->player.rotation_speed);
	game->player.dir.y = dir.x * sin(game->player.rotation_speed)
		+ dir.y * cos(game->player.rotation_speed);
	game->player.plane.x = plane.x * cos(game->player.rotation_speed)
		- plane.y * sin(game->player.rotation_speed);
	game->player.plane.y = plane.x * sin(game->player.rotation_speed)
		+ plane.y * cos(game->player.rotation_speed);
}

void	rotate_fov(t_game *game)
{
	if (game->key.rotate_left)
		rotate_left(game);
	else if (game->key.rotate_right)
		rotate_right(game);
}
