#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#define BACKGROUND "./background.xpm"
#define WINDOW_X 320 * 2
#define WINDOW_Y 200 * 2

typedef struct s_image
{
	void	*img;
	int		x;
	int		y;
}t_image;


#include <mlx.h>

int main() {
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WINDOW_X, WINDOW_Y, "My Image");
    void *img = mlx_new_image(mlx, WINDOW_X, WINDOW_Y);
    int bits_per_pixel;
    int size_line;
    int endian;
    int *data = (int*)mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
    int i, j;
    int blue = mlx_get_color_value(mlx, 0x000000);
    int black = mlx_get_color_value(mlx, 0x11031C);
    for (i = 0; i < WINDOW_Y; i++) {
        for (j = 0; j < WINDOW_X; j++) {
            if (i < WINDOW_Y / 2) {
                data[i * WINDOW_X + j] = blue;
            } else {
                data[i * WINDOW_X + j] = black;
            }
        }
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
    return 0;
}

