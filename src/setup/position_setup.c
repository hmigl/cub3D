#include "cub3d.h"

static char	get_direction(t_scene_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_as_2d_array[i])
	{
		j = 0;
		while (map->map_as_2d_array[i][j])
		{
			if (ft_strchr("NSEW", map->map_as_2d_array[i][j]))
				return (map->map_as_2d_array[i][j]);
			j++;
		}
		i++;
	}
	return ('N');
}

void	position_setup(t_game *game, double radians)
{
	t_vector	direction;
	t_vector	plane;
	double		old_dir_x;
	double		old_plane_x;

	direction = game->dir;
	plane = game->plane;
	old_dir_x = direction.x;
	old_plane_x = plane.x;
	game->dir.x = direction.x * cos(radians) - direction.y * sin(-radians);
	game->dir.y = old_dir_x * sin(-radians) + direction.y * cos(-radians);
	game->plane.x = plane.x * cos(-radians) - plane.y * sin(-radians);
	game->plane.y = old_plane_x * sin(-radians) + plane.y * cos(-radians);
}

double	get_radians(t_game *game)
{
	char	direction;

	direction = get_direction(&game->scene->map);
	if (direction == 'N')
		return (0);
	else if (direction == 'S')
		return (M_PI);
	else if (direction == 'E')
		return (M_PI / 2);
	else if (direction == 'W')
		return (M_PI * 1.5);
	return (0);
}

