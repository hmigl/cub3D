#include "cub3d.h"

static enum e_type_id	get_type_id(const char *element)
{
	if (!ft_strncmp(element, "NO", 2)
		|| !ft_strncmp(element, "SO", 2)
		|| !ft_strncmp(element, "WE", 2)
		|| !ft_strncmp(element, "EA", 2))
		return (PATH_TO_TEXTURE);
	else
		return (COLOR);
}

static void	fetch_element(t_scene *scene, const char *line)
{
	char			possible_scene_element[3];
	enum e_type_id	type_identifier;

	ft_strlcpy(possible_scene_element, line, 3);
	type_identifier = get_type_id(possible_scene_element);
	if (type_identifier == PATH_TO_TEXTURE)
		;
	else
		;
}

static int	is_valid_scene_element(const char *e)
{
	return (!ft_strncmp(e, "NO ", 3)
		|| !ft_strncmp(e, "SO ", 3)
		|| !ft_strncmp(e, "WE ", 3)
		|| !ft_strncmp(e, "EA ", 3)
		|| !ft_strncmp(e, "F ", 2)
		|| !ft_strncmp(e, "C ", 2));
}

static char	*gnl_trim(int fd)
{
	char	*line;
	char	*buffer;

	buffer = get_next_line(fd);
	if (buffer == NULL || ft_strrchr(buffer, '\n') == NULL)
		return (NULL);
	line = ft_strtrim(buffer, "\n");
	free(buffer);
	return (line);
}

void	fetch_scene_elements(t_scene *scene)
{
	char	*line;

	line = gnl_trim(scene->fd);
	while (line != NULL)
	{
		if (is_valid_scene_element(line))
			fetch_element(scene, line);
		free(line);
		line = gnl_trim(scene->fd);
	}
}
