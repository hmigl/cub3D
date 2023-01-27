#include "cub3d.h"

void	display_error_msg_and_exit(enum e_error_desc desc)
{
	char	*error_msg;

	if (desc == WRONG_USAGE)
		error_msg = "usage: ./cub3d FILE\n";
	else if (desc == INVALID_EXT)
		error_msg = "file must contain '.cub' extension\n";
	else if (desc == MISSING_ELEMENT)
		error_msg = "scene has missing elements, check your file\n";
	else if (desc == REDUNDANT_ELEMENT)
		error_msg = "scene has redundant elements, check your file\n";
	else
		error_msg = "an unknown error has occurred\n";
	write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	exit(1);
}
