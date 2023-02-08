#include "cub3d.h"

typedef struct s_flood_fill	t_flood_fill;
struct s_flood_fill {
	int		x;
	int		y;
	int		rows;
	int		cols;
	char	**map;
};

static char	**dup_2d_array(char **arr, int rows)
{
	int		i;
	char	**copy;

	copy = ft_calloc(rows + 1, sizeof(char *));
	i = -1;
	while (++i < rows)
		copy[i] = ft_strdup(arr[i]);
	return (copy);
}

static int	flood_fill(struct s_flood_fill args, int x, int y)
{
	if (args.map[x][y] == ' ')
		return (0);
	if (args.map[x][y] == '0')
	{
		args.map[x][y] = '.';
		if (x == 0 || x == args.rows - 1 || y == 0 || y == args.cols - 1)
			return (0);
		if (!flood_fill(args, x - 1, y))
			return (0);
		if (!flood_fill(args, x + 1, y))
			return (0);
		if (!flood_fill(args, x, y - 1))
			return (0);
		if (!flood_fill(args, x, y + 1))
			return (0);
		if (!flood_fill(args, x + 1, y + 1))
			return (0);
		if (!flood_fill(args, x + 1, y - 1))
			return (0);
		if (!flood_fill(args, x - 1, y - 1))
			return (0);
		if (!flood_fill(args, x - 1, y + 1))
			return (0);
	}
	return (1);
}

int	is_map_surrounded_by_walls(t_scene_map *map)
{
	int				is_surrounded;
	t_flood_fill	args;

	args.x = map->x_start_pos;
	args.y = map->y_start_pos;
	args.rows = map->rows;
	args.cols = map->cols;
	args.map = dup_2d_array(map->map_as_2d_array, map->rows);
	args.map[args.x][args.y] = '0';
	is_surrounded = flood_fill(args, args.x, args.y);
	ft_free_matrix(args.map);
	return (is_surrounded);
}
