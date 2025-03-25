/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:39:21 by ebini             #+#    #+#             */
/*   Updated: 2025/03/24 17:53:43 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "so_long_defs.h"
#include "settings.h"

double	point_distance(t_point *a, t_point *b)
{
	return (sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2)));
}

double	square_distance(t_square *a, t_square *b)
{
	const double	center_a_x = a->pos.x - a->size / 2;
	const double	center_a_y = a->pos.y - a->size / 2;
	const double	center_b_x = b->pos.x - b->size / 2;
	const double	center_b_y = b->pos.y - b->size / 2;

	return (sqrt(
			fabs(center_a_x - center_b_x)
			+ fabs(center_a_y - center_b_y)));
}

double	player_square_distance(t_player *player, t_index *square_position)
{
	t_square	player_box;
	t_square	square_box;

	player_box.pos = player->pos;
	player_box.size = player->width;
	square_box.pos.x = (double)square_position->x;
	square_box.pos.y = (double)square_position->y;
	square_box.size = CELL_SIZE;
	return (square_distance(&player_box, &square_box));
}
