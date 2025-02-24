/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:40:04 by ebini             #+#    #+#             */
/*   Updated: 2025/02/24 18:57:53 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "so_long.h"
#include "settings.h"

#include <stdio.h>	

void	calc_area(t_player *player, t_vec movement,
	t_index *start, t_area *size)
{
	const t_point	next_pos = {
		player->pos.x + movement.x, player->pos.y + movement.y};

	start->x = (int)(fmin(player->pos.x, next_pos.x) / CELL_SIZE);
	start->y = (int)(fmin(player->pos.y, next_pos.y) / CELL_SIZE);
	size->w = 1 + (int)(fabs(player->pos.x - next_pos.x) / CELL_SIZE);
	size->h = 1 + (int)(fabs(player->pos.y - next_pos.y) / CELL_SIZE);
}

t_index	update_nearest_collision(t_player *player, t_vec movement,
	t_index area_pos, t_index nearest_collision)
{
	if (check_player_movement_square(player, movement,
		area_pos.x, area_pos.y))
	{
		if (nearest_collision.x == -1
			|| player_square_distance(player, area_pos)
			< player_square_distance(player, nearest_collision))
			nearest_collision = area_pos;
	}
	return (nearest_collision);
}

t_index	get_nearest_collision(t_map *map, t_player *player, t_vec movement)
{
	t_index	area_pos;
	t_area	area_size;
	t_index current_pos;
	t_index	nearest_collision;

	nearest_collision = (t_index){-1, -1};
	calc_area(player, movement, &area_pos, &area_size);
	while (--area_size.h)
	{
		while (--area_size.w)
		{
			current_pos.x = area_pos.x + area_size.w;
			current_pos.x = area_pos.y + area_size.h;
			if (get_map(map, current_pos.x, current_pos.y) != '0')
				nearest_collision = update_nearest_collision(player, movement,
					current_pos, nearest_collision);
		}
	}
	return (nearest_collision);
}
