#include "cub3d.h"

static int	open_file(const char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	return (fd);
}

void	parse_scene_desc(t_scene_desc *scene, const char *filepath)
{
	if (!ft_check_ext(filepath, ".cub"))
		display_error_msg_and_exit(INVALID_EXT);
	scene->fd = open_file(filepath);
	extract_scene_elements(scene);
	extract_scene_map(scene);
}
