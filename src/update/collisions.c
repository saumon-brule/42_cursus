/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:40:04 by ebini             #+#    #+#             */
/*   Updated: 2025/03/19 00:05:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "so_long.h"
#include "settings.h"

#include <stdio.h>

void	update_nearest_collision(t_game *game, t_segment *vertice_movement,
	t_collision *nearest_collision)
{
	t_collision	vertice_collision;
	
	vertice_collision = get_nearest_vertice_collision(game, vertice_movement);
	if (vertice_collision.collides)
	{
		if (!nearest_collision->collides)
			*nearest_collision = vertice_collision;
		else if (player_square_distance(game->player,
			&(vertice_collision.index)) < player_square_distance(game->player,
			&(nearest_collision->index)))
			*nearest_collision = vertice_collision;
	}
}

t_collision	get_nearest_collision(t_game *game, t_vec movement)
{
	const t_player	*player = game->player;
	t_collision		nearest_collision;
	t_segment		vertice_movement;

	nearest_collision.collides = false;
	vertice_movement.vec = movement;
	vertice_movement.pos = player->pos;
	update_nearest_collision(game, &vertice_movement, &nearest_collision);
	vertice_movement.pos = (t_point){player->pos.x + player->width,
		player->pos.y};
	update_nearest_collision(game, &vertice_movement, &nearest_collision);
	vertice_movement.pos = (t_point){player->pos.x,
		player->pos.y + player->height};
	update_nearest_collision(game, &vertice_movement, &nearest_collision);
	vertice_movement.pos = (t_point){player->pos.x + player->width,
		player->pos.y + player->height};
	update_nearest_collision(game, &vertice_movement, &nearest_collision);
	return (nearest_collision);
}
