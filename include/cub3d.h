#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_scene_desc	t_scene;

struct s_scene_desc {
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_color;
	char	*ceilling_color;
	int		fd;
};

enum e_error_desc {
	WRONG_USAGE,
	INVALID_EXT,
};

// error handling
void	display_error_msg_and_exit(enum e_error_desc desc);

// parsing
void	parse_scene(t_scene *scene, const char *filepath);

#endif // CUB3D_H
