/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 06:53:14 by ebini             #+#    #+#             */
/*   Updated: 2025/03/24 19:19:18 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"

void	draw_player(t_game *game)
{
	draw_img_on_screen(game->player->sprite, game, game->player->pos);
	if (game->settings->debug_enabled)
	{
		draw_line(game, game->debug->vertice_movements);
		draw_line(game, game->debug->vertice_movements + 1);
		draw_line(game, game->debug->vertice_movements + 2);
		draw_line(game, game->debug->vertice_movements + 3);
	}
}
