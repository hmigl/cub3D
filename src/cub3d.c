/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:57:57 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/10 16:57:59 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pre_raycasting_setup(t_game *game)
{
	game->player.move_speed = MOVE_SPEED;
	game->player.rotation_speed = ROTATION_SPEED;
	vectors_setup(game);
	mlx_setup(game);
	position_setup(game, get_radians(game));
	textures_setup(game);
}

int	main(int argc, char *argv[])
{
	t_scene_desc	scene;
	t_game			game;

	if (argc != 2)
		display_error_msg_and_exit(WRONG_USAGE);
	scene = (struct s_scene_desc){0};
	game = (struct s_game){0};
	parse_scene_desc(&scene, argv[1]);
	game.scene = &scene;
	pre_raycasting_setup(&game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
