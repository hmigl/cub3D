#include "cub3d.h"

static int	keypress_management(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		exit_game_gracefully(game);
	return (0);
}

static void	set_hooks(t_game *game)
{
	mlx_hook(game->mlx.win_ptr,
		KeyPress, KeyPressMask, &keypress_management, game);
	mlx_hook(game->mlx.win_ptr,
		DestroyNotify, NoEventMask, &exit_game_gracefully, game);
	mlx_loop_hook(game->mlx.mlx_ptr, &render, game);
}

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
	set_hooks(game);
}
