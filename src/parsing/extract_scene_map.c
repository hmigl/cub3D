#include "cub3d.h"

static void	save_map_as_list(t_scene_desc *scene)
{
	char	*line;
	t_list	*lines_as_list;

	line = scene->map->first_line;
	lines_as_list = NULL;
	while (line != NULL)
	{
		ft_lstadd_back(&lines_as_list, ft_lstnew(line));
		line = gnl_trim(scene->fd, 6);
	}
	scene->map->lines_as_list = lines_as_list;
}

void	extract_scene_map(t_scene_desc *scene)
{
	save_map_as_list(scene);
	if (!map_premises_honored(scene->map))
		;
}
