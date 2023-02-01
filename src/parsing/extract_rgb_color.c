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
	while (++i < 3)
	{
		value = ft_atoi(rgb_ranges[i]);
		if (!(value >= 0 && value <= 255))
			display_error_msg_and_exit(MALFORMED_ELEMENT);
	}
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

static void	check_element_redundancy(const char *line)
{
	int			floor_or_ceiling;
	static int	extracted_colors[2] = {0};

	floor_or_ceiling = line[0] == 'C';
	extracted_colors[floor_or_ceiling]++;
	if (extracted_colors[floor_or_ceiling] > 1)
		display_error_msg_and_exit(REDUNDANT_ELEMENT);
}

void	extract_rgb_color(t_scene_desc *scene, const char *line)
{
	char	**rgb_ranges;
	int		info_index;
	int		rgb_value;

	if (line[2] == ' ')
		info_index = 3;
	else
		info_index = 2;
	check_element_redundancy(line);
	count_commas(&(line[info_index]));
	rgb_ranges = ft_split(&(line[info_index]), ',');
	check_rgb_colors_range(rgb_ranges);
	rgb_value = convert_rgb(
			ft_atoi(rgb_ranges[0]),
			ft_atoi(rgb_ranges[1]),
			ft_atoi(rgb_ranges[2]));
	ft_free_matrix(rgb_ranges);
	if (line[0] == 'F')
		scene->floor_color = rgb_value;
	else
		scene->ceiling_color = rgb_value;
}
