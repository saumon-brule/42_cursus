/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_segment_square_collision.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:41:16 by ebini             #+#    #+#             */
/*   Updated: 2025/03/25 01:04:32 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "so_long.h"
#include "settings.h"
#include "libft.h"

t_collision	segment_intersection(t_segment *a, t_segment *b)
{
	double			u;
	double			v;
	t_collision		collision;
	const double	det = a->vec.x * b->vec.y - a->vec.y * b->vec.x;

	if (fabs(det) < 1e-9)
	{
		collision.collides = false;
		return (collision);
	}
	u = (b->vec.x * (a->pos.y - b->pos.y) - b->vec.y * (a->pos.x - b->pos.x))
		/ det;
	if (b->vec.x > b->vec.y)
		v = (u * a->vec.x + a->pos.x - b->pos.x) / b->vec.x;
	else
		v = (u * a->vec.y + a->pos.y - b->pos.y) / b->vec.y;
	collision.collides = (0 <= u && u <= 1 && 0 <= v && v <= 1);
	collision.pos.x = a->pos.x + u * a->vec.x;
	collision.pos.y = a->pos.y + u * a->vec.y;
	return (collision);
}

void	update_segment_square_collision(t_segment *segment, t_segment *edge,
	t_collision *collision)
{
	t_collision	intersection;

	intersection = segment_intersection(segment, edge);
	if (intersection.collides)
	{
		if (!collision->collides
			|| point_distance(&(segment->pos), &(intersection.pos))
			< point_distance(&(segment->pos), &(collision->pos)))
		{
			collision->collides = true;
			collision->pos = intersection.pos;
		}
	}
}

t_collision	check_segment_square_collision(t_segment *segment, t_square *square)
{
	t_segment	edge;
	t_collision	collision;

	collision.collides = false;
	edge.pos = square->pos;
	edge.vec = (t_vec){0, square->size};
	update_segment_square_collision(segment, &edge, &collision);
	edge.vec = (t_vec){square->size, 0};
	update_segment_square_collision(segment, &edge, &collision);
	edge.pos = (t_point){square->pos.x, square->pos.y + square->size};
	edge.vec = (t_vec){0, square->size};
	update_segment_square_collision(segment, &edge, &collision);
	edge.pos = (t_point){square->pos.x + square->size, square->pos.y};
	edge.vec = (t_vec){square->size, 0};
	update_segment_square_collision(segment, &edge, &collision);
	return (collision);
}
