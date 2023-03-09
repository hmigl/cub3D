#include "cub3d.h"

static void	move_right(t_game *game)
{
	int		next_x;
	int		next_y;
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
	if (map[next_x][(int)game->player.pos.y] == FLOOR)
		game->player.pos.x += move_x;
	if (map[(int)game->player.pos.x][next_y] == FLOOR)
		game->player.pos.y += move_y;
}

static void	move_left(t_game *game)
{
	int		next_x;
	int		next_y;
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
	if (map[next_x][(int)game->player.pos.y] == FLOOR)
		game->player.pos.x += move_x;
	if (map[(int)game->player.pos.x][next_y] == FLOOR)
		game->player.pos.y += move_y;
}

static void	move_backward(t_game *game)
{
	int		next_x;
	int		next_y;
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
	if (map[next_x][(int)game->player.pos.y] == FLOOR)
		game->player.pos.x += move_x;
	if (map[(int)game->player.pos.x][next_y] == FLOOR)
		game->player.pos.y += move_y;
}

static void	move_forward(t_game *game)
{
	int		next_x;
	int		next_y;
	char	**map;
	double	move_x;
	double	move_y;

	map = game->scene->map.map_as_2d_array;
	move_x = game->player.dir.x * game->player.move_speed;
	move_y = game->player.dir.y * game->player.move_speed;
	next_x = game->player.pos.x + move_x
		+ copysign(WALL_COLLISION_THRESHOLD, move_x);
	next_y = game->player.pos.y + move_y
		+ copysign(WALL_COLLISION_THRESHOLD, move_y);
	if (map[next_x][(int)game->player.pos.y] == FLOOR)
		game->player.pos.x += move_x;
	if (map[(int)game->player.pos.x][next_y] == FLOOR)
		game->player.pos.y += move_y;
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == XK_w)
		move_forward(game);
	if (keycode == XK_s)
		move_backward(game);
	if (keycode == XK_a)
		move_left(game);
	if (keycode == XK_d)
		move_right(game);
}
