/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_vertice_collision.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 02:19:49 by ebini             #+#    #+#             */
/*   Updated: 2025/03/30 06:35:55 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "settings.h"
#include "so_long.h"

void	calc_area(t_segment *segment, t_map *map, t_index *start, t_area *size)
{
	const t_point	next_pos = {segment->pos.x + segment->vec.x, segment->pos.y
		+ segment->vec.y};

	if (segment->pos.x < next_pos.x)
	{
		start->x = (int)(segment->pos.x / CELL_SIZE);
		size->w = 1 + (int)(next_pos.x / CELL_SIZE) - start->x;
	}
	else
	{
		start->x = (int)(next_pos.x / CELL_SIZE);
		size->w = 1 + (int)(segment->pos.x / CELL_SIZE) - start->x;
	}
	if (segment->pos.y < next_pos.y)
	{
		start->y = (int)(segment->pos.y / CELL_SIZE);
		size->h = 1 + (int)(next_pos.y / CELL_SIZE - start->y);
	}
	else
	{
		start->y = (int)(next_pos.y / CELL_SIZE);
		size->h = 1 + (int)(segment->pos.y / CELL_SIZE - start->y);
	}
	size->w = min(size->w, map->width - start->x - 1);
	size->h = min(size->h, map->height - start->y - 1);
}

void	update_nearest_vertice_collision(t_segment *vertice_movement,
	t_index square_pos, t_collision *collision)
{
	t_collision	new_collision;
	t_square	current_square;

	current_square.pos.x = square_pos.x * CELL_SIZE;
	current_square.pos.y = square_pos.y * CELL_SIZE;
	current_square.size = CELL_SIZE;
	new_collision = check_segment_square_collision(vertice_movement,
			&current_square);
	if (new_collision.collides)
	{
		if (!collision->collides
			|| point_distance(&(vertice_movement->pos), &(new_collision.pos))
			< point_distance(&(vertice_movement->pos), &(collision->pos)))
		{
			*collision = new_collision;
			collision->index = square_pos;
		}
	}
}

t_collision	get_nearest_vertice_collision(t_game *game,
	t_segment *vertice_movement)
{
	t_index		area_pos;
	t_area		area_size;
	int			area_width;
	t_index		current_pos;
	t_collision	collision;

	collision.collides = false;
	calc_area(vertice_movement, &(game->map), &area_pos, &area_size);
	area_width = area_size.w;
	while (area_size.h--)
	{
		area_size.w = area_width;
		while (area_size.w--)
		{
			current_pos.x = area_pos.x + area_size.w;
			current_pos.y = area_pos.y + area_size.h;
			if (get_map(&(game->map), current_pos.x, current_pos.y) != '0')
			{
				update_nearest_vertice_collision(vertice_movement, current_pos,
					&collision);
			}
		}
	}
	return (collision);
}
