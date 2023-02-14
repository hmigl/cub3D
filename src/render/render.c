#include "cub3d.h"

void	draw_background(t_game *game)
{
	int	i;
	int	j;
	int	floor_color;
	int	ceil_color;

	ceil_color = mlx_get_color_value(game->mlx, 0x000000);
	floor_color = mlx_get_color_value(game->mlx, 0x11031C);
	if (game->data->img)
		mlx_destroy_image(game->mlx, game->data->img);
	game->data->img = mlx_new_image(game->mlx, WINDOW_X, WINDOW_Y);
	game->data->addr = (int*)mlx_get_data_addr(game->data->img, &game->data->bits_per_pixel, &game->data->size_line, &game->data->endian);
	i = 0;
	while (i < WINDOW_Y) 
	{
		j = 0;
		while (j < WINDOW_X) 
		{
			if (i < WINDOW_Y / 2) 
				game->data->addr[i * WINDOW_X + j] = ceil_color;
			else 
				game->data->addr[i * WINDOW_X + j] = floor_color;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->data->img, 0, 0);
}

int	render(t_game *game)
{
	draw_background(game);
	return (0);
}

int	press_key(int key_code)
{
	if (key_code == XK_Escape)
		exit(0);
	return (0);
}

int	release_key(int key_code)
{
	if (key_code == XK_Escape)
		exit(0);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}

void	game_run(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, press_key, NULL);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, release_key, NULL);
	mlx_hook(game->win, 17, 0L, ft_exit, NULL);
	mlx_loop(game->mlx);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_X, WINDOW_Y, "cub3D");
	game->data = malloc(sizeof(t_data));
	game_run(game);
}