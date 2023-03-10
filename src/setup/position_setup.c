/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:08:20 by hepiment          #+#    #+#             */
/*   Updated: 2023/03/10 17:08:21 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	position_setup(t_game *game, double radians)
{
	t_vector	direction;
	t_vector	plane;
	double		old_dir_x;
	double		old_plane_x;

	direction = game->player.dir;
	plane = game->player.plane;
	old_dir_x = direction.x;
	old_plane_x = plane.x;
	game->player.dir.x = direction.x * cos(radians)
		- direction.y * sin(-radians);
	game->player.dir.y = old_dir_x * sin(-radians)
		+ direction.y * cos(-radians);
	game->player.plane.x = plane.x * cos(-radians)
		- plane.y * sin(-radians);
	game->player.plane.y = old_plane_x * sin(-radians)
		+ plane.y * cos(-radians);
}

double	get_radians(t_game *game)
{
	if (game->scene->map.player_dir == 'N')
		return (0);
	else if (game->scene->map.player_dir == 'S')
		return (M_PI);
	else if (game->scene->map.player_dir == 'E')
		return (M_PI / 2);
	else if (game->scene->map.player_dir == 'W')
		return (M_PI * 1.5);
	return (0);
}
