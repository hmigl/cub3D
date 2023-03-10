/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_desc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:57:37 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/10 16:57:41 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_file(const char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
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
	close(scene->fd);
}
