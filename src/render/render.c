#include "cub3d.h"

void	draw_background(t_game *game, t_data *data)
{
	int	i;
	int	j;
	int	floor_color;
	int	ceil_color;

	ceil_color = mlx_get_color_value(game->mlx, 0x000000);
	floor_color = mlx_get_color_value(game->mlx, 0x11031C);
	data->img = mlx_new_image(game->mlx, WINDOW_X, WINDOW_Y);
	data->addr = (int*)mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->size_line, &data->endian);
	i = 0;
	j = 0;
	while (i < WINDOW_Y) 
	{
		j = 0;
		while (j < WINDOW_X) 
		{
			if (i < WINDOW_Y / 2) 
				data->addr[i * WINDOW_X + j] = ceil_color;
			else 
				data->addr[i * WINDOW_X + j] = floor_color;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, data->img, 0, 0);
}

void	init_window(t_game *game, t_data *data)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_X, WINDOW_Y, "cube");
	draw_background(game, data);
	mlx_loop(game->mlx);
}
