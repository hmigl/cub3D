#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FUNCTIONAL_MAP_MIN_SIZE 3
# define VALID_CHARS "01 NSEW"
# define PLAYER_CHARS "NSEW"

# define WRONG_USAGE "usage: ./cub3D FILE"
# define INVALID_EXT "file must end with '.cub' extension"
# define MISSING_ELEMENT "scene has missing elements"
# define REDUNDANT_ELEMENT "scene has redundant elements"
# define MALFORMED_ELEMENT "malformed scene element(s)"
# define INVALID_MAP "invalid map"

typedef struct s_scene_map	t_scene_map;
struct s_scene_map {
	char	*first_line;
	t_list	*rows_as_list;
	int		cols;
	int		rows;
	char	**map_as_2d_array;
	int		x_start_pos;
	int		y_start_pos;
};

typedef struct s_scene_desc	t_scene_desc;
struct s_scene_desc {
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			floor_color;
	int			ceiling_color;
	int			fd;
	t_scene_map	map;
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
void	display_error_msg_and_exit(char *error_msg);

// memory management
void	scene_clean_up(t_scene_desc *scene);
void	map_clean_up(t_scene_map *map);

// parsing
void	parse_scene_desc(t_scene_desc *scene, const char *filepath);
void	extract_scene_elements(t_scene_desc *scene);
void	extract_texture_path(t_scene_desc *scene, const char *line);
void	extract_rgb_color(t_scene_desc *scene, const char *line);
void	extract_scene_map(t_scene_desc *scene);
char	*gnl_trim(int fd, int extracted_elements);

// map validation
int		map_premises_honored(t_scene_map *map);
int		is_map_surrounded_by_walls(t_scene_map *map);

#endif // CUB3D_H
