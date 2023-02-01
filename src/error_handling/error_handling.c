#include "cub3d.h"

void	display_error_msg_and_exit(char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	exit(1);
}
