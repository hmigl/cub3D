#include "cub3d.h"

static void	save_map_as_list(t_scene_desc *scene)
{
	char	*line;
	t_list	*rows_as_list;

	line = scene->map->first_line;
	rows_as_list = NULL;
	while (line != NULL)
	{
		ft_lstadd_back(&rows_as_list, ft_lstnew(line));
		line = gnl_trim(scene->fd, 6);
	}
	scene->map->rows_as_list = rows_as_list;
}

void	extract_scene_map(t_scene_desc *scene)
{
	save_map_as_list(scene);
	if (!map_premises_honored(scene->map))
		;
}
