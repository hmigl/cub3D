/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_scene_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:57:36 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/10 16:57:41 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_starting_info(t_scene_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_as_2d_array[++i])
	{
		j = -1;
		while (map->map_as_2d_array[i][++j])
		{
			if (ft_strchr(PLAYER_CHARS, map->map_as_2d_array[i][j]))
			{
				map->x_start_pos = i;
				map->y_start_pos = j;
				map->player_dir = map->map_as_2d_array[i][j];
				map->map_as_2d_array[i][j] = FLOOR;
				return ;
			}
		}
	}
}

static char	*cease_diff(int diff, char *row)
{
	char	*tmp;
	char	*ceased_diff_str;

	tmp = ft_calloc(diff + 1, sizeof(char));
	while (diff != 0)
		tmp[--diff] = ' ';
	ceased_diff_str = ft_strjoin(row, tmp);
	free(tmp);
	return (ceased_diff_str);
}

static void	reconstruct_map_as_2d_array(t_scene_map *map)
{
	int		i;
	int		diff;
	char	*row;
	t_list	*aux;

	map->map_as_2d_array = ft_calloc(map->rows + 1, sizeof(char *));
	aux = map->rows_as_list;
	i = -1;
	while (++i < map->rows)
	{
		row = ft_strdup(map->rows_as_list->content);
		diff = map->cols - ft_strlen(row);
		if (diff != 0)
			row = cease_diff(diff, row);
		map->map_as_2d_array[i] = row;
		map->rows_as_list = map->rows_as_list->next;
	}
	map->rows_as_list = aux;
	map->map_as_2d_array[map->rows] = NULL;
}

static void	save_map_as_list(t_scene_desc *scene)
{
	char	*line;
	t_list	*rows_as_list;

	line = scene->map.first_line;
	rows_as_list = NULL;
	while (line != NULL)
	{
		ft_lstadd_back(&rows_as_list, ft_lstnew(line));
		line = gnl_trim(scene->fd, 6);
	}
	scene->map.rows_as_list = rows_as_list;
}

void	extract_scene_map(t_scene_desc *scene)
{
	save_map_as_list(scene);
	if (!map_premises_honored(&(scene->map)))
	{
		scene_clean_up(scene);
		display_error_msg_and_exit(INVALID_MAP);
	}
	reconstruct_map_as_2d_array(&(scene->map));
	set_player_starting_info(&(scene->map));
	if (!is_map_surrounded_by_walls(&(scene->map)))
	{
		scene_clean_up(scene);
		display_error_msg_and_exit(INVALID_MAP);
	}
}
