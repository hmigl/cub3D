#include "cub3d.h"

static int	get_longest_line_size(t_list *head)
{
	t_list	*aux;
	int		longest_line_size;
	int		current_lize_size;

	if (head == NULL)
		return (-1);
	longest_line_size = ft_strlen(head->content);
	aux = head->next;
	current_lize_size = -1;
	while (aux != NULL)
	{
		current_lize_size = ft_strlen(aux->content);
		if (current_lize_size > longest_line_size)
			longest_line_size = current_lize_size;
		aux = aux->next;
	}
	return (longest_line_size);
}

int	map_premises_honored(t_scene_map *map)
{
	map->longest_line = get_longest_line_size(map->lines_as_list);
	map->lines = ft_lstsize(map->lines_as_list);
	if (map->lines_as_list == NULL)
		return (0);
	if (map->longest_line < FUNCTIONAL_MAP_MIN_SIZE
		|| map->lines < FUNCTIONAL_MAP_MIN_SIZE)
		return (0);
	return (1);
}
