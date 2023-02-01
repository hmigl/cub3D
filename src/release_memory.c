#include "cub3d.h"

void	map_clean_up(t_scene_map *map)
{
	if (map == NULL)
		return ;
	ft_lstclear(&(map->rows_as_list), &free);
}

void	scene_clean_up(t_scene_desc *scene)
{
	if (scene == NULL)
		return ;
	map_clean_up(&(scene->map));
	free(scene->no_texture);
	free(scene->so_texture);
	free(scene->ea_texture);
	free(scene->we_texture);
}
