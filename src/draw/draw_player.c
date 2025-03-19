/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 06:53:14 by ebini             #+#    #+#             */
/*   Updated: 2025/03/19 00:36:36 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"

void	draw_player(t_game *game)
{
	t_segment	vertice_movement;

	draw_img_on_screen(game->player->sprite, game, game->player->pos);
	if (game->settings->debug_enabled)
	{
		vertice_movement.pos = game->player->pos;
		vertice_movement.vec = (t_vec){game->player->speed.x * game->dt, game->player->speed.y * game->dt};
		draw_line(game, &vertice_movement);
	}
}
