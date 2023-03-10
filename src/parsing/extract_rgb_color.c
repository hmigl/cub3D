/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_rgb_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:57:35 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/10 16:57:40 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	convert_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

static void	check_rgb_colors_range(char **rgb_ranges)
{
	int	i;
	int	value;

	i = -1;
	while (rgb_ranges[++i] != NULL)
	{
		value = ft_atoi(rgb_ranges[i]);
		if (!(value >= 0 && value <= 255))
			display_error_msg_and_exit(MALFORMED_ELEMENT);
	}
	if (i != 3 || rgb_ranges[2] == NULL)
		display_error_msg_and_exit(MALFORMED_ELEMENT);
}

static void	count_commas(const char *str)
{
	int	i;
	int	comma_count;

	i = -1;
	comma_count = 0;
	while (++i < (int)ft_strlen(str))
		if (str[i] == ',')
			comma_count++;
	if (comma_count != 2)
		display_error_msg_and_exit(MALFORMED_ELEMENT);
}

static int	is_element_redundant(char *line)
{
	int			floor_or_ceiling;
	static int	extracted_colors[2] = {0};

	floor_or_ceiling = line[0] == 'C';
	extracted_colors[floor_or_ceiling]++;
	return (extracted_colors[floor_or_ceiling] > 1);
}

void	extract_rgb_color(t_scene_desc *scene, char *line)
{
	char	**rgb_ranges;
	int		info_index;
	int		rgb_value;

	info_index = 2;
	if (line[2] == ' ')
		info_index = 3;
	if (is_element_redundant(line))
	{
		free(line);
		scene_clean_up(scene);
		display_error_msg_and_exit(REDUNDANT_ELEMENT);
	}
	count_commas(&(line[info_index]));
	rgb_ranges = ft_split(&(line[info_index]), ',');
	check_rgb_colors_range(rgb_ranges);
	rgb_value = convert_rgb(ft_atoi(rgb_ranges[0]), ft_atoi(rgb_ranges[1]),
			ft_atoi(rgb_ranges[2]));
	ft_free_matrix(rgb_ranges);
	if (line[0] == 'F')
		scene->floor_color = rgb_value;
	else
		scene->ceiling_color = rgb_value;
}
