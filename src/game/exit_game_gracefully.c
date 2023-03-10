/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_gracefully.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:57:35 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/10 16:57:40 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game_gracefully(t_game *game)
{
	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	mlx_destroy_image(game->mlx.mlx_ptr, game->screen.img);
	mlx_destroy_image(game->mlx.mlx_ptr, game->no_texture.img);
	mlx_destroy_image(game->mlx.mlx_ptr, game->so_texture.img);
	mlx_destroy_image(game->mlx.mlx_ptr, game->ea_texture.img);
	mlx_destroy_image(game->mlx.mlx_ptr, game->we_texture.img);
	mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	mlx_destroy_display(game->mlx.mlx_ptr);
	free(game->mlx.mlx_ptr);
	game_clean_up(game);
	exit(0);
}
