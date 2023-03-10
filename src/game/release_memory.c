/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:57:35 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/10 16:57:40 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_clean_up(t_scene_map *map)
{
	if (map == NULL)
		return ;
	printf("Cleaning map data\n");
	ft_free_matrix(map->map_as_2d_array);
	ft_lstclear(&(map->rows_as_list), &free);
	*(map) = (struct s_scene_map){0};
}

void	scene_clean_up(t_scene_desc *scene)
{
	if (scene == NULL)
		return ;
	map_clean_up(&(scene->map));
	printf("Cleaning scene description data\n");
	free(scene->no_texture);
	free(scene->so_texture);
	free(scene->ea_texture);
	free(scene->we_texture);
	*(scene) = (struct s_scene_desc){0};
}

void	game_clean_up(t_game *game)
{
	if (game == NULL)
		return ;
	scene_clean_up(game->scene);
	printf("Cleaning game data\n");
	*(game) = (struct s_game){0};
}
