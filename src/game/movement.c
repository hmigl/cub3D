#include "cub3d.h"

static void	move_right(t_game *game)
{
	double		next_x;
	double		next_y;
	char	**map;
	double	move_x;
	double	move_y;

	map = game->scene->map.map_as_2d_array;
	move_x = game->player.dir.y * game->player.move_speed;
	move_y = -game->player.dir.x * game->player.move_speed;
	next_x = game->player.pos.x + move_x
		+ copysign(WALL_COLLISION_THRESHOLD, move_x);
	next_y = game->player.pos.y + move_y
		+ copysign(WALL_COLLISION_THRESHOLD, move_y);
	if (map[(int)game->player.pos.x][(int)game->player.pos.y] != FLOOR)
		return;

	// Check for collision at adjacent positions
	if (map[(int)next_x][(int)game->player.pos.y] != FLOOR)
		move_x = 0;
	if (map[(int)game->player.pos.x][(int)next_y] != FLOOR)
		move_y = 0;

	// Check for diagonal collisions
	if (map[(int)next_x][(int)next_y] != FLOOR)
		return;

	game->player.pos.x += move_x;
	game->player.pos.y += move_y;
	// if (map[(int)next_x][(int)game->player.pos.y] == FLOOR)
	// 	game->player.pos.x += move_x;
	// if (map[(int)game->player.pos.x][(int)next_y] == FLOOR)
	// 	game->player.pos.y += move_y;
}

static void	move_left(t_game *game)
{
	double		next_x;
	double		next_y;
	char	**map;
	double	move_x;
	double	move_y;

	map = game->scene->map.map_as_2d_array;
	move_x = -game->player.dir.y * game->player.move_speed;
	move_y = game->player.dir.x * game->player.move_speed;
	next_x = game->player.pos.x + move_x
		+ copysign(WALL_COLLISION_THRESHOLD, move_x);
	next_y = game->player.pos.y + move_y
		+ copysign(WALL_COLLISION_THRESHOLD, move_y);
	if (map[(int)game->player.pos.x][(int)game->player.pos.y] != FLOOR)
		return;

	// Check for collision at adjacent positions
	if (map[(int)next_x][(int)game->player.pos.y] != FLOOR)
		move_x = 0;
	if (map[(int)game->player.pos.x][(int)next_y] != FLOOR)
		move_y = 0;

	// Check for diagonal collisions
	if (map[(int)next_x][(int)next_y] != FLOOR)
		return;

	game->player.pos.x += move_x;
	game->player.pos.y += move_y;
	// if (map[(int)next_x][(int)game->player.pos.y] == FLOOR)
	// 	game->player.pos.x += move_x;
	// if (map[(int)game->player.pos.x][(int)next_y] == FLOOR)
	// 	game->player.pos.y += move_y;
}

static void	move_backward(t_game *game)
{
	double	next_x;
	double	next_y;
	char	**map;
	double	move_x;
	double	move_y;

	map = game->scene->map.map_as_2d_array;
	move_x = -game->player.dir.x * game->player.move_speed;
	move_y = -game->player.dir.y * game->player.move_speed;
	next_x = game->player.pos.x + move_x
		+ copysign(WALL_COLLISION_THRESHOLD, move_x);
	next_y = game->player.pos.y + move_y
		+ copysign(WALL_COLLISION_THRESHOLD, move_y);

	if (map[(int)game->player.pos.x][(int)game->player.pos.y] != FLOOR)
		return;

	// Check for collision at adjacent positions
	if (map[(int)next_x][(int)game->player.pos.y] != FLOOR)
		move_x = 0;
	if (map[(int)game->player.pos.x][(int)next_y] != FLOOR)
		move_y = 0;

	// Check for diagonal collisions
	if (map[(int)next_x][(int)next_y] != FLOOR)
		return;

	game->player.pos.x += move_x;
	game->player.pos.y += move_y;
	// if (map[(int)next_x][(int)game->player.pos.y] == FLOOR)
	//	game->player.pos.x += move_x;
	// if (map[(int)game->player.pos.x][(int)next_y] == FLOOR)
	//	game->player.pos.y += move_y;
}

static void move_forward(t_game *game)
{
	double	next_x;
	double	next_y;
	char	**map;
	double	move_x;
	double	move_y;

	map = game->scene->map.map_as_2d_array;
	move_x = game->player.dir.x * game->player.move_speed;
	move_y = game->player.dir.y * game->player.move_speed;
	next_x = game->player.pos.x + move_x + copysign(WALL_COLLISION_THRESHOLD, move_x);
	next_y = game->player.pos.y + move_y + copysign(WALL_COLLISION_THRESHOLD, move_y);

	// Check for collision at current position
	if (map[(int)game->player.pos.x][(int)game->player.pos.y] != FLOOR)
		return;

	// Check for collision at adjacent positions
	if (map[(int)next_x][(int)game->player.pos.y] != FLOOR)
		move_x = 0;
	if (map[(int)game->player.pos.x][(int)next_y] != FLOOR)
		move_y = 0;

	// Check for diagonal collisions
	if (map[(int)next_x][(int)next_y] != FLOOR)
		return;

	game->player.pos.x += move_x;
	game->player.pos.y += move_y;
}

void	move_player(t_game *game)
{
	if (game->key.w)
		move_forward(game);
	if (game->key.s)
		move_backward(game);
	if (game->key.a)
		move_left(game);
	if (game->key.d)
		move_right(game);
	rotate_fov(game);
}
