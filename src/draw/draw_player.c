/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 06:53:14 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 05:00:43 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "settings.h"

#include <stdio.h>

void	draw_player(t_game *game)
{
	draw_img_on_screen(game->sprites.player, game, (t_tuple){
		game->player_pos.x * CELL_SIZE, game->player_pos.y * CELL_SIZE});
}
