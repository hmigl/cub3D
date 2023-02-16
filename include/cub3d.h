#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysymdef.h>

# define FUNCTIONAL_MAP_MIN_SIZE 3
# define VALID_CHARS "01 NSEW"
# define PLAYER_CHARS "NSEW"

# define WRONG_USAGE "usage: ./cub3D FILE"
# define INVALID_EXT "file must end with '.cub' extension"
# define MISSING_ELEMENT "scene has missing elements"
# define REDUNDANT_ELEMENT "scene has redundant elements"
# define MALFORMED_ELEMENT "malformed scene element(s)"
# define INVALID_MAP "invalid map"
# define MLX_ERROR "mlx failed"

# define WINDOW_X 700 
# define WINDOW_Y 430

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

typedef struct s_img		t_img;
struct s_img {
	char	*name;
	int		*addr;
	void	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

typedef struct s_mlx		t_mlx;
struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	// t_img	img;
};

typedef struct s_game		t_game;
struct s_game {
	t_mlx			mlx;
	t_scene_desc	*scene;
	// t_img	*s;
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
void	game_clean_up(t_game *game);

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

// setup
void	mlx_setup(t_game *game);

// render
void	init_window(t_game *game);

#endif // CUB3D_H
