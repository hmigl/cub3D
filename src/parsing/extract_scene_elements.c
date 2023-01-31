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

static int	extract_element(t_scene_desc *scene, const char *line)
{
	char			scene_element[3];
	enum e_type_id	type_identifier;

	ft_strlcpy(scene_element, line, 3);
	type_identifier = get_type_id(scene_element);
	if (type_identifier == PATH_TO_TEXTURE)
		extract_texture_path(scene, line);
	else
		extract_rgb_color(scene, line);
	return (1);
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

void	extract_scene_elements(t_scene_desc *scene)
{
	int		elements;
	char	*line;

	elements = 0;
	line = gnl_trim(scene->fd, elements);
	while (line != NULL)
	{
		if (is_valid_scene_element(line))
			elements += extract_element(scene, line);
		else if (!is_valid_scene_element(line) && line[0] != '\0')
			break ;
		free(line);
		line = gnl_trim(scene->fd, elements);
	}
	if (elements != 6)
		display_error_msg_and_exit(MISSING_ELEMENT);
}
