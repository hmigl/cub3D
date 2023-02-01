#include "cub3d.h"

static int	get_longest_row_size(t_list *head)
{
	t_list	*aux;
	int		longest_row_size;
	int		current_row_size;

	if (head == NULL)
		return (-1);
	longest_row_size = ft_strlen(head->content);
	aux = head->next;
	current_row_size = -1;
	while (aux != NULL)
	{
		current_row_size = ft_strlen(aux->content);
		if (current_row_size > longest_row_size)
			longest_row_size = current_row_size;
		aux = aux->next;
	}
	return (longest_row_size);
}

int	map_premises_honored(t_scene_map *map)
{
	map->longest_line = get_longest_row_size(map->rows_as_list);
	map->rows = ft_lstsize(map->rows_as_list);
	if (map->rows_as_list == NULL)
		return (0);
	if (map->longest_line < FUNCTIONAL_MAP_MIN_SIZE
		|| map->rows < FUNCTIONAL_MAP_MIN_SIZE)
		return (0);
	return (1);
}
