#include "cub3d.h"

void	fseek_end(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static int	copy_char(const char c, int trimmed_index, char *trimmed)
{
	if (trimmed_index == 0)
	{
		if (c != ' ' && c != '\t')
			trimmed[trimmed_index++] = c;
	}
	else if (trimmed_index == 1 || trimmed_index == 2)
	{
		if (c == ' ' || c == '\t')
			trimmed[trimmed_index++] = ' ';
		else
			trimmed[trimmed_index++] = c;
	}
	else
	{
		if (!ft_isspace(c))
			trimmed[trimmed_index++] = c;
	}
	return (trimmed_index);
}

static char	*trim_line(const char *line)
{
	int		i;
	int		len;
	int		trimmed_index;
	char	*trimmed_line;

	if (line == NULL)
		return (NULL);
	i = 0;
	trimmed_index = 0;
	len = ft_strlen(line);
	trimmed_line = ft_calloc(len + 1, sizeof(char));
	while (i < len)
	{
		if (line[i] == '\n')
			break ;
		trimmed_index = copy_char(line[i++], trimmed_index, trimmed_line);
	}
	return (trimmed_line);
}

char	*gnl_trim(int fd, int extracted_elements)
{
	char	*line;
	char	*buffer;

	buffer = get_next_line(fd);
	if (extracted_elements != 6)
		line = trim_line(buffer);
	else
		line = ft_strtrim(buffer, "\n");
	free(buffer);
	return (line);
}
