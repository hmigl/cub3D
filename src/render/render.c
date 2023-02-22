#include "cub3d.h"

static void	draw_ceiling_and_floor(t_game *game, int ceiling_color,
									int floor_color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i < WIN_HEIGHT / 2)
				game->screen->addr[i * WIN_WIDTH + j] = ceiling_color;
			else
				game->screen->addr[i * WIN_WIDTH + j] = floor_color;
			j++;
		}
		i++;
	}
}

static void	draw_background(t_game *game)
{
	if (game->screen->img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->screen->img);
	game->screen->img = mlx_new_image(game->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	game->screen->addr = (int *) mlx_get_data_addr(game->screen->img,
			&game->screen->bits_per_pixel,
			&game->screen->size_line,
			&game->screen->endian);
	draw_ceiling_and_floor(game,
		game->scene->ceiling_color, game->scene->floor_color);
	mlx_put_image_to_window(game->mlx.mlx_ptr,
		game->mlx.win_ptr, game->screen->img, 0, 0);
}

int	render(t_game *game)
{
	draw_background(game);
	
	return (0);
}
