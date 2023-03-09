#include "cub3d.h"

int	get_color(t_img *texture, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (1);
	dst = (char *)texture->addr + (y * texture->size_line + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = ((char *) game->screen.addr) + (y * game->screen.size_line + x
			* (game->screen.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	texture_loop(t_game *game, int x)
{
	int	y;
	int	color;

	y = game->rc.draw_start;
	while (y < game->rc.draw_end)
	{
		game->rc.tex.y = (int)game->rc.tex_pos & (game->rc.texture->height - 1);
		game->rc.tex_pos += game->rc.tex_step;
		color = get_color(game->rc.texture, game->rc.tex.x, game->rc.tex.y);
		put_pixel(game, x, y, color);
		y++;
	}
}
