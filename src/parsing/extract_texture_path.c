#include "cub3d.h"

static void	set_texture_path(int texture_value, const char *path,
							t_scene *scene)
{
	if (texture_value == NO)
		scene->no_texture = ft_strdup(path);
	else if (texture_value == SO)
		scene->so_texture = ft_strdup(path);
	else if (texture_value == EA)
		scene->ea_texture = ft_strdup(path);
	else
		scene->we_texture = ft_strdup(path);
}

static int	find_object_info(const char *leading_spcs_start)
{
	int	info_index;

	info_index = 0;
	while (leading_spcs_start[info_index])
	{
		if (leading_spcs_start[info_index] == ' ')
			info_index++;
		else
			break ;
	}
	return (info_index + 2);
}

static enum e_texture_path	get_direction_value(const char c)
{
	if (c == 'N')
		return (NO);
	else if (c == 'S')
		return (SO);
	else if (c == 'E')
		return (EA);
	else if (c == 'W')
		return (WE);
	return (-1);
}

void	extract_texture_path(t_scene *scene, const char *line)
{
	int			texture_file_fd;
	int			texture_numerical_value;
	const char	*leading_spcs_start;
	static int	textures_freq[4] = {0};

	texture_numerical_value = get_direction_value(line[0]);
	textures_freq[texture_numerical_value]++;
	if (textures_freq[texture_numerical_value] > 1)
		display_error_msg_and_exit(REDUNDANT_ELEMENT);
	leading_spcs_start = &(line[2]);
	texture_file_fd
		= open(&(line[find_object_info(leading_spcs_start)]), O_RDONLY);
	if (texture_file_fd == -1)
	{
		perror("open");
		exit(1);
	}
	close(texture_file_fd);
	set_texture_path(texture_numerical_value,
		&(line[find_object_info(leading_spcs_start)]), scene);
}
