#include "cub3d.h"

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
	if (game->scene->map.player_dir == 'N')
		return (0);
	else if (game->scene->map.player_dir == 'S')
		return (M_PI);
	else if (game->scene->map.player_dir == 'E')
		return (M_PI / 2);
	else if (game->scene->map.player_dir == 'W')
		return (M_PI * 1.5);
	return (0);
}
