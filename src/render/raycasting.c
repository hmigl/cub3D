/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:07:46 by hepiment          #+#    #+#             */
/*   Updated: 2023/03/10 17:07:49 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_wall_height(t_game *game)
{
	if (game->rc.side == 0)
		game->rc.perp_wall_dist = game->rc.side_dist.x - game->rc.delta_dist.x;
	else
		game->rc.perp_wall_dist = game->rc.side_dist.y - game->rc.delta_dist.y;
	game->rc.line_height = (int)(WIN_HEIGHT / game->rc.perp_wall_dist);
	game->rc.draw_start = -game->rc.line_height / 2 + WIN_HEIGHT / 2;
	if (game->rc.draw_start < 0)
		game->rc.draw_start = 0;
	game->rc.draw_end = game->rc.line_height / 2 + WIN_HEIGHT / 2;
	if (game->rc.draw_end >= WIN_HEIGHT)
		game->rc.draw_end = WIN_HEIGHT - 1;
}

static void	set_raycaster_data(t_game *game, int x)
{
	game->rc.camera.x = 2 * x / (double) WIN_WIDTH - 1;
	game->rc.ray_dir.x = game->player.dir.x + game->player.plane.x
		* game->rc.camera.x;
	game->rc.ray_dir.y = game->player.dir.y + game->player.plane.y
		* game->rc.camera.x;
	game->rc.map.x_i = (int) game->player.pos.x;
	game->rc.map.y_i = (int) game->player.pos.y;
	game->rc.delta_dist.x = fabs(1 / game->rc.ray_dir.x);
	game->rc.delta_dist.y = fabs(1 / game->rc.ray_dir.y);
}

void	raycast(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		set_raycaster_data(game, x);
		calc_next_step(game);
		cast_rays_using_dda(game);
		set_wall_height(game);
		insert_texture(game, x);
	}
}
