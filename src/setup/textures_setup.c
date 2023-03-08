#include "cub3d.h"

static void	load_texture(t_game *game, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path,
			&texture->width, &texture->height);
	texture->addr = (int *) mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, \
			&texture->size_line, \
			&texture->endian);
}

static void	init_texture(t_game *game)
{
	load_texture(game, game->no_texture, game->scene->no_texture);
	load_texture(game, game->so_texture, game->scene->so_texture);
	load_texture(game, game->we_texture, game->scene->we_texture);
	load_texture(game, game->ea_texture, game->scene->ea_texture);
}

void	textures_setup(t_game *game)
{
	game->no_texture = (t_img *)malloc(sizeof(t_img));
	game->so_texture = (t_img *)malloc(sizeof(t_img));
	game->we_texture = (t_img *)malloc(sizeof(t_img));
	game->ea_texture = (t_img *)malloc(sizeof(t_img));
	init_texture(game);
}
