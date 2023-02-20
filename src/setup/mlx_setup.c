#include "cub3d.h"

void	mlx_setup(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
	{
		game_clean_up(game);
		display_error_msg_and_exit(MLX_ERROR);
	}
	game->screen = malloc(sizeof(t_img));
	game->mlx.win_ptr
		= mlx_new_window(game->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
}
