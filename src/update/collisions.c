/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:40:04 by ebini             #+#    #+#             */
/*   Updated: 2025/03/24 20:51:55 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "so_long.h"
#include "settings.h"

#include <stdio.h>

void	update_nearest_collision(t_game *game, t_segment *vertice_movement,
	t_collision *nearest_collision, int vertice_index)
{
	t_collision	vertice_collision;

	vertice_collision = get_nearest_vertice_collision(game, vertice_movement);
	vertice_collision.vertice_index = vertice_index;
	if (vertice_collision.collides)
	{
		if (!nearest_collision->collides)
			*nearest_collision = vertice_collision;
		else if (player_square_distance(game->player,
				&(vertice_collision.index)) < player_square_distance(
				game->player, &(nearest_collision->index)))
			*nearest_collision = vertice_collision;
	}
}

t_collision	get_nearest_collision(t_game *game, t_vec movement,
		t_segment *vertice_movement_array)
{
	const t_player	*player = game->player;
	t_collision		nearest_collision;
	t_segment		vertice_movement;

	nearest_collision.collides = false;
	vertice_movement.vec = movement;
	vertice_movement.pos = player->pos;
	// printf("%.3f, %.3f\n", vertice_movement.vec.x, vertice_movement.vec.y);
	vertice_movement_array[0] = vertice_movement;
	update_nearest_collision(game, &vertice_movement, &nearest_collision, 0);
	vertice_movement.pos = (t_point){player->pos.x + player->width,
		player->pos.y};
	vertice_movement_array[1] = vertice_movement;
	update_nearest_collision(game, &vertice_movement, &nearest_collision, 1);
	vertice_movement.pos = (t_point){player->pos.x,
		player->pos.y + player->height};
	vertice_movement_array[2] = vertice_movement;
	update_nearest_collision(game, &vertice_movement, &nearest_collision, 2);
	vertice_movement.pos = (t_point){player->pos.x + player->width,
		player->pos.y + player->height};
	vertice_movement_array[3] = vertice_movement;
	update_nearest_collision(game, &vertice_movement, &nearest_collision, 3);
	return (nearest_collision);
}
