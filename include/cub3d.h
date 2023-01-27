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
	MISSING_ELEMENT,
	REDUNDANT_ELEMENT
};

enum e_type_id {
	PATH_TO_TEXTURE,
	COLOR
};

enum e_texture_path {
	NO,
	SO,
	EA,
	WE
};

// error handling
void	display_error_msg_and_exit(enum e_error_desc desc);

// parsing
void	parse_scene(t_scene *scene, const char *filepath);
void	extract_scene_elements(t_scene *scene);
void	extract_texture_path(t_scene *scene, const char *line);
char	*trim_line(const char *line);

#endif // CUB3D_H
