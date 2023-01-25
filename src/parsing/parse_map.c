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

void	parse_scene(t_scene *scene, const char *filepath)
{
	if (!ft_check_ext(filepath, ".cub"))
		display_error_msg_and_exit(INVALID_EXT);
	scene->fd = open_file(filepath);
	fetch_scene_elements(scene);
	printf("%s\n", scene->no_texture);
	printf("%s\n", scene->so_texture);
	printf("%s\n", scene->ea_texture);
	printf("%s\n", scene->we_texture);
}
