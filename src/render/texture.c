#include "cub3d.h"

static void	set_texture(t_game *game)
{
	game->rc.texture = game->no_texture;
	if (game->rc.side == 1 && game->rc.ray_dir.y < 0)
		game->rc.texture = game->we_texture;
	else if (game->rc.side == 1)
		game->rc.texture = game->ea_texture;
	else if (game->rc.side == 0 && game->rc.ray_dir.x > 0)
		game->rc.texture = game->so_texture;
}

static void	load_texture(t_game *game, t_img *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path,
			&texture->width, &texture->height);
	texture->addr = mlx_get_data_addr(texture->img,
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

void	insert_texture(t_game *game, int x)
{
	if (game->rc.side == 0)
		game->rc.wall.x = game->player.y + game->rc.perp_wall_dist
			* game->rc.ray_dir.y;
	else
		game->rc.wall.x = game->player.x + game->rc.perp_wall_dist
			* game->rc.ray_dir.x;
	game->rc.wall.x -= (int)game->rc.wall.x;
	init_texture(game);
	set_texture(game);
	game->rc.tex.x = (int)(game->rc.wall.x * (double)game->rc.texture->width);
	if (game->rc.side == 0 && game->rc.ray_dir.x > 0)
		game->rc.tex.x = game->rc.texture->width - game->rc.tex.x - 1;
	if (game->rc.side == 1 && game->rc.ray_dir.y < 0)
		game->rc.tex.x = game->rc.texture->width - game->rc.tex.x - 1;
	game->rc.tex_step = 1.0 * game->rc.texture->height / game->rc.line_height;
	game->rc.tex_pos = (game->rc.draw_start - WIN_HEIGHT
			/ 2 + game->rc.line_height / 2) * game->rc.tex_step;
	//texture_loop(game, x);
}
