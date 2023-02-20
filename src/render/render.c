#include "cub3d.h"

void	draw_background(t_game *game)
{
	int	i;
	int	j;
	int	floor_color;
	int	ceil_color;

	ceil_color = mlx_get_color_value(game->mlx.mlx_ptr, 0x000000);
	floor_color = mlx_get_color_value(game->mlx.mlx_ptr, 0x11031C);
	if (game->screen->img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->screen->img);
	game->screen->img = mlx_new_image(game->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	game->screen->addr = (int*)mlx_get_data_addr(game->screen->img, &game->screen->bits_per_pixel, &game->screen->size_line, &game->screen->endian);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i < WIN_HEIGHT / 2)
				game->screen->addr[i * WIN_WIDTH + j] = ceil_color;
			else 
				game->screen->addr[i * WIN_WIDTH + j] = floor_color;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr, game->screen->img, 0, 0);
}

int	render(t_game *game)
{
	draw_background(game);
	return (0);
}
