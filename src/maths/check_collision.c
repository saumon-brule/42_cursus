/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:41:16 by ebini             #+#    #+#             */
/*   Updated: 2025/02/23 16:36:01 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "so_long_defs.h"
#include "settings.h"

bool	check_segment_segment(t_segment *a, t_segment *b)
{
	double			u;
	double			v;
	const double	det = a->vec.x * b->vec.y - a->vec.y * b->vec.x;

	if (fabs(det) < 1e-9)
		return (0);
	u = (b->vec.x * (a->pos.y - b->pos.y) - b->vec.y * (a->pos.x - b->pos.x))
		/ det;
	if (b->vec.x > b->vec.y)
		v = (u * a->vec.x + a->pos.x - b->pos.x) / b->vec.x;
	else
		v = (u * a->vec.y + a->pos.y - b->pos.y) / b->vec.y;
	return (u >= 0 && u <= 1 && v >= 0 && v <= 1);
}

bool	check_segment_square(t_segment *segment, t_square *square)
{
	t_segment	edge;

	edge.pos = square->pos;
	edge.vec = (t_vec){0, square->size};
	if (check_segment_segment(segment, &edge))
		return (true);
	edge.pos = square->pos;
	edge.vec = (t_vec){square->size, 0};
	if (check_segment_segment(segment, &edge))
		return (true);
	edge.pos = (t_point){square->pos.x, square->pos.y + square->size};
	edge.vec = (t_vec){0, square->size};
	if (check_segment_segment(segment, &edge))
		return (true);
	edge.pos = (t_point){square->pos.x + square->size, square->pos.y};
	edge.vec = (t_vec){square->size, 0};
	if (check_segment_segment(segment, &edge))
		return (true);
	return (false);
}

bool	check_player_movement_square(t_player *player, t_vec movement,
	int x, int y)
{
	t_square	square;
	t_segment	vertice_movement;

	square.pos = (t_point){x, y};
	square.size = CELL_SIZE;
	vertice_movement.vec = movement;
	vertice_movement.pos = player->pos;
	if (check_segment_square(&vertice_movement, &square))
		return (true);
	vertice_movement.pos = (t_point){player->pos.x + player->width,
		player->pos.y};
	if (check_segment_square(&vertice_movement, &square))
		return (true);
	vertice_movement.pos = (t_point){player->pos.x,
		player->pos.y + player->height};
	if (check_segment_square(&vertice_movement, &square))
		return (true);
	vertice_movement.pos = (t_point){player->pos.x + player->width,
		player->pos.y + player->height};
	if (check_segment_square(&vertice_movement, &square))
		return (true);
	return (false);
}
