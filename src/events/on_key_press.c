/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:25:35 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 04:44:59 by ebini            ###   ########lyon.fr   */
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
		move_player(game, -1, 0);
	else if (keycode == GAME_KEY_RIGHT)
		move_player(game, 1, 0);
	else if (keycode == GAME_KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == GAME_KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == GAME_KEY_EXIT)
		exit_game(game);
	return (0);
}
