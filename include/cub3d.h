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
# include <X11/keysym.h>
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

# define WIN_HEIGHT 430
# define WIN_WIDTH 700
# define WIN_TITLE "cub3D"

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
};

typedef struct s_vector		t_vector;
struct s_vector {
	union {
		double	x;
		int		x_i;
	};
	union {
		double	y;
		int		y_i;
	};
};

typedef struct s_raycaster	t_raycaster;
struct s_raycaster {
	t_vector	delta_dist;
	t_vector	side_dist;
	t_vector	ray_dir;
	t_vector	camera;
	t_vector	map;
	t_vector	step;
	int			hit;
	int			side;
};

typedef struct s_game		t_game;
struct s_game {
	t_mlx			mlx;
	t_scene_desc	*scene;
	t_img			*screen;
	t_vector		plane;
	t_vector		direction;
	t_vector		player;
	t_raycaster		raycaster;
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
void	vectors_setup(t_game *game);

// render
int		render(t_game *game);
void	raycast(t_game *game);
// raycasting
void	calc_next_step(t_game *game);
void	cast_rays_using_dda(t_game *game);

// other
int		exit_game_gracefully(t_game *game);

#endif // CUB3D_H
