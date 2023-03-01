#include "cub3d.h"

static void	set_texture(t_game *game)
{
	game->rc.texture.img = game->scene->no_texture;
	if (game->rc.side == 1 && game->rc.ray_dir.y < 0)
		game->rc.texture.img = game->scene->we_texture;
	else if (game->rc.side == 1)
		game->rc.texture.img = game->scene->ea_texture;
	else if (game->rc.side == 0 && game->rc.ray_dir.x > 0)
		game->rc.texture.img = game->scene->so_texture;
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
	set_texture(game);
	game->rc.tex.x = (int)(game->rc.wall.x * (double)game->rc.texture.width);
	if (game->rc.side == 0 && game->rc.ray_dir.x > 0)
		game->rc.tex.x = game->rc.texture.width - game->rc.tex.x - 1;
	if (game->rc.side == 1 && game->rc.ray_dir.y < 0)
		game->rc.tex.x = game->rc.texture.width - game->rc.tex.x - 1;
	game->rc.tex_step = 1.0 * game->rc.texture.height / game->rc.line_height;
	game->rc.tex_pos = (game->rc.draw_start - WIN_HEIGHT
			/ 2 + game->rc.line_height / 2) * game->rc.tex_step;
	//texture_loop(game, x);
}
