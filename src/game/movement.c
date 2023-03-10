/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:57:35 by hmigl             #+#    #+#             */
/*   Updated: 2023/03/10 16:57:40 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_right(t_game *game)
{
	t_player	*p;
	char		**map;

	map = game->scene->map.map_as_2d_array;
	p = &(game->player);
	p->move_x = p->dir.y * p->move_speed;
	p->move_y = -p->dir.x * p->move_speed;
	p->next_x = p->pos.x + p->move_x
		+ copysign(WALL_COLLISION_THRESHOLD, p->move_x);
	p->next_y = p->pos.y + p->move_y
		+ copysign(WALL_COLLISION_THRESHOLD, p->move_y);
	if (map[(int)p->pos.x][(int)p->pos.y] != FLOOR)
		return ;
	if (map[(int)p->next_x][(int)p->pos.y] != FLOOR)
		p->move_x = 0;
	if (map[(int)p->pos.x][(int)p->next_y] != FLOOR)
		p->move_y = 0;
	if (map[(int)p->next_x][(int)p->next_y] != FLOOR)
		return ;
	p->pos.x += p->move_x;
	p->pos.y += p->move_y;
}

static void	move_left(t_game *game)
{
	t_player	*p;
	char		**map;

	map = game->scene->map.map_as_2d_array;
	p = &(game->player);
	p->move_x = -p->dir.y * p->move_speed;
	p->move_y = p->dir.x * p->move_speed;
	p->next_x = p->pos.x + p->move_x
		+ copysign(WALL_COLLISION_THRESHOLD, p->move_x);
	p->next_y = p->pos.y + p->move_y
		+ copysign(WALL_COLLISION_THRESHOLD, p->move_y);
	if (map[(int)p->pos.x][(int)p->pos.y] != FLOOR)
		return ;
	if (map[(int)p->next_x][(int)p->pos.y] != FLOOR)
		p->move_x = 0;
	if (map[(int)p->pos.x][(int)p->next_y] != FLOOR)
		p->move_y = 0;
	if (map[(int)p->next_x][(int)p->next_y] != FLOOR)
		return ;
	p->pos.x += p->move_x;
	p->pos.y += p->move_y;
}

static void	move_backward(t_game *game)
{
	t_player	*p;
	char		**map;

	map = game->scene->map.map_as_2d_array;
	p = &(game->player);
	p->move_x = -p->dir.x * p->move_speed;
	p->move_y = -p->dir.y * p->move_speed;
	p->next_x = p->pos.x + p->move_x
		+ copysign(WALL_COLLISION_THRESHOLD, p->move_x);
	p->next_y = p->pos.y + p->move_y
		+ copysign(WALL_COLLISION_THRESHOLD, p->move_y);
	if (map[(int)p->pos.x][(int)p->pos.y] != FLOOR)
		return ;
	if (map[(int)p->next_x][(int)p->pos.y] != FLOOR)
		p->move_x = 0;
	if (map[(int)p->pos.x][(int)p->next_y] != FLOOR)
		p->move_y = 0;
	if (map[(int)p->next_x][(int)p->next_y] != FLOOR)
		return ;
	p->pos.x += p->move_x;
	p->pos.y += p->move_y;
}

static void	move_forward(t_game *game)
{
	t_player	*p;
	char		**map;

	map = game->scene->map.map_as_2d_array;
	p = &(game->player);
	p->move_x = p->dir.x * p->move_speed;
	p->move_y = p->dir.y * p->move_speed;
	p->next_x = p->pos.x + p->move_x
		+ copysign(WALL_COLLISION_THRESHOLD, p->move_x);
	p->next_y = p->pos.y + p->move_y
		+ copysign(WALL_COLLISION_THRESHOLD, p->move_y);
	if (map[(int)p->pos.x][(int)p->pos.y] != FLOOR)
		return ;
	if (map[(int)p->next_x][(int)p->pos.y] != FLOOR)
		p->move_x = 0;
	if (map[(int)p->pos.x][(int)p->next_y] != FLOOR)
		p->move_y = 0;
	if (map[(int)p->next_x][(int)p->next_y] != FLOOR)
		return ;
	p->pos.x += p->move_x;
	p->pos.y += p->move_y;
}

void	move_player(t_game *game)
{
	if (game->key.w)
		move_forward(game);
	if (game->key.s)
		move_backward(game);
	if (game->key.a)
		move_left(game);
	if (game->key.d)
		move_right(game);
	rotate_fov(game);
}
