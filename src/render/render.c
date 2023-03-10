#include "cub3d.h"

static void	draw_background(t_game *game)
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
				put_pixel(game, j, i, game->scene->ceiling_color);
			else
				put_pixel(game, j, i, game->scene->floor_color);
			j++;
		}
		i++;
	}
}

int	render(t_game *game)
{
	move_player(game);
	draw_background(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr,
		game->mlx.win_ptr, game->screen.img, 0, 0);
	return (0);
}
