#include "cub3d.h"

static void	move_right(t_game *game)
{
	char	**map;
	int		next_x;
	int		next_y;

	map = game->scene->map.map_as_2d_array;
	next_x = game->player.pos.x + game->player.dir.y * game->player.move_speed;
	next_y = game->player.pos.y - game->player.dir.x * game->player.move_speed;
	if (map[next_x][(int)game->player.pos.y] == '0')
		game->player.pos.x += game->player.dir.y * game->player.move_speed;
	if (map[(int)game->player.pos.x][next_y] == '0')
		game->player.pos.y -= game->player.dir.x * game->player.move_speed;
}

static void	move_left(t_game *game)
{
	char	**map;
	int		next_x;
	int		next_y;

	map = game->scene->map.map_as_2d_array;
	next_x = game->player.pos.x - game->player.dir.y * game->player.move_speed;
	next_y = game->player.pos.y + game->player.dir.x * game->player.move_speed;
	if (map[next_x][(int)game->player.pos.y] == '0')
		game->player.pos.x -= game->player.dir.y * game->player.move_speed;
	if (map[(int)game->player.pos.x][next_y] == '0')
		game->player.pos.y += game->player.dir.x * game->player.move_speed;
}

static void	move_backward(t_game *game)
{
	char	**map;
	int		next_x;
	int		next_y;

	map = game->scene->map.map_as_2d_array;
	next_x = game->player.pos.x - game->player.dir.x * game->player.move_speed;
	next_y = game->player.pos.y - game->player.dir.y * game->player.move_speed;
	if (map[next_x][(int)game->player.pos.y] == '0')
		game->player.pos.x -= game->player.dir.x * game->player.move_speed;
	if (map[(int)game->player.pos.x][next_y] == '0')
		game->player.pos.y -= game->player.dir.y * game->player.move_speed;
}

static void	move_forward(t_game *game)
{
	char	**map;
	int		next_x;
	int		next_y;

	map = game->scene->map.map_as_2d_array;
	next_x = game->player.pos.x + game->player.dir.x * game->player.move_speed;
	next_y = game->player.pos.y + game->player.dir.y * game->player.move_speed;
	if (map[next_x][(int)game->player.pos.y] == '0')
		game->player.pos.x += game->player.dir.x * game->player.move_speed;
	if (map[(int)game->player.pos.x][next_y] == '0')
		game->player.pos.y += game->player.dir.y * game->player.move_speed;
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
