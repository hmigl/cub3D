#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map	t_map;

struct s_map {
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_color;
	char	*ceilling_color;
	int		fd;
};

// error handling
void	display_usage_and_exit(void);

// parsing
void	parse_map(t_map *map, const char *filepath);

#endif // CUB3D_H
