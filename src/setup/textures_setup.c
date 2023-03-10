/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:08:29 by hepiment          #+#    #+#             */
/*   Updated: 2023/03/10 17:08:30 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	textures_setup(t_game *game)
{
	load_texture(game, &(game->no_texture), game->scene->no_texture);
	load_texture(game, &(game->so_texture), game->scene->so_texture);
	load_texture(game, &(game->we_texture), game->scene->we_texture);
	load_texture(game, &(game->ea_texture), game->scene->ea_texture);
}
