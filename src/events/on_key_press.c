/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:25:35 by ebini             #+#    #+#             */
/*   Updated: 2025/03/21 15:15:11 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/keysym.h>

#include "so_long.h"
#include "settings.h"

#include <stdio.h>

int	on_key_press(int keycode, t_game *game)
{
	if (keycode == GAME_KEY_LEFT)
		game->player->acc.x -= MOVEMENT_ACCELERATION;
	else if (keycode == GAME_KEY_RIGHT)
		game->player->acc.x += MOVEMENT_ACCELERATION;
	else if (keycode == GAME_KEY_UP)
		game->player->acc.y -= MOVEMENT_ACCELERATION;
	else if (keycode == GAME_KEY_DOWN)
		game->player->acc.y += MOVEMENT_ACCELERATION;
	else if (keycode == GAME_KEY_DEBUG)
		game->settings->debug_enabled = !game->settings->debug_enabled;
	else if (keycode == GAME_KEY_EXIT)
		exit_game(game);
	return (0);
}
