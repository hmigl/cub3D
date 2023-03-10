/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:08:33 by hepiment          #+#    #+#             */
/*   Updated: 2023/03/10 17:08:34 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_starting_position(t_game *game)
{
	game->player.pos.x = game->scene->map.x_start_pos
		+ WALL_COLLISION_THRESHOLD;
	game->player.pos.y = game->scene->map.y_start_pos
		+ WALL_COLLISION_THRESHOLD;
}

static void	setup_camera_plane(t_game *game)
{
	game->player.plane.x = 0;
	game->player.plane.y = 0.66;
}

static void	setup_facing_direction(t_game *game)
{
	game->player.dir.x = -1;
	game->player.dir.y = 0;
}

void	vectors_setup(t_game *game)
{
	setup_facing_direction(game);
	setup_camera_plane(game);
	setup_starting_position(game);
}
