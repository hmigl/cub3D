#include "cub3d.h"

int	exit_game_gracefully(t_game *game)
{
	mlx_loop_end(game->mlx.mlx_ptr);
	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	mlx_destroy_display(game->mlx.mlx_ptr);
	free(game->mlx.mlx_ptr);
	game->mlx.mlx_ptr = NULL;
	exit(0);
}
