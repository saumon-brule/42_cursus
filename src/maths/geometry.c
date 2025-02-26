/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:39:21 by ebini             #+#    #+#             */
/*   Updated: 2025/02/24 18:54:56 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "so_long_defs.h"
#include "settings.h"

double	square_distance(t_square *a, t_square *b)
{
	const t_point	centera = {a->pos.x - a->size / 2, a->pos.y - a->size / 2};
	const t_point	centerb = {b->pos.x - b->size / 2, b->pos.y - b->size / 2};

	return (sqrt(fabs(centera.x - centerb.x) + fabs(centera.y - centerb.y)));
}

double	player_square_distance(t_player *player, t_index square_position)
{
	t_square	player_box;
	t_square	square_box;

	player_box.pos = player->pos;
	player_box.size = player->width;
	square_box.pos.x = (double)square_position.x;
	square_box.pos.y = (double)square_position.y;
	square_box.pos.y = CELL_SIZE;
	return (square_distance(&player_box, &square_box));
}
