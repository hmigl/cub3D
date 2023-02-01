#include "cub3d.h"

void	display_error_msg_and_exit(char *error_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(1);
}
