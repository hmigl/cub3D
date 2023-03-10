/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:57:36 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/10 16:57:41 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_texture_path(int direction, const char *path,
							t_scene_desc *scene)
{
	if (direction == NO && scene->no_texture == NULL)
		scene->no_texture = ft_strdup(path);
	else if (direction == SO && scene->so_texture == NULL)
		scene->so_texture = ft_strdup(path);
	else if (direction == EA && scene->ea_texture == NULL)
		scene->ea_texture = ft_strdup(path);
	else if (direction == WE && scene->we_texture == NULL)
		scene->we_texture = ft_strdup(path);
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

void	extract_texture_path(t_scene_desc *scene, char *line)
{
	int			texture_file_fd;
	int			direction_numerical_value;
	static int	extracted_directions[4] = {0};

	direction_numerical_value = get_direction_value(line[0]);
	extracted_directions[direction_numerical_value]++;
	if (extracted_directions[direction_numerical_value] > 1)
	{
		free(line);
		fseek_end(scene->fd);
		scene_clean_up(scene);
		display_error_msg_and_exit(REDUNDANT_ELEMENT);
	}
	texture_file_fd = open(&(line[3]), O_RDONLY);
	if (texture_file_fd == -1)
	{
		free(line);
		scene_clean_up(scene);
		display_error_msg_and_exit(BAD_FILE_DESCRIPTOR);
	}
	close(texture_file_fd);
	set_texture_path(direction_numerical_value, &(line[3]), scene);
}
