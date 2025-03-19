/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:25:35 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 23:17:35 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/keysym.h>

#include "so_long.h"
#include "settings.h"

#include <stdio.h>

int	on_key_press(int keycode, t_game *game)
{
	if (keycode == XK_a)
		game->player->acc.x -= MOVEMENT_ACCELERATION;
	else if (keycode == XK_d)
		game->player->acc.x += MOVEMENT_ACCELERATION;
	else if (keycode == XK_w)
		game->player->acc.y -= MOVEMENT_ACCELERATION;
	else if (keycode == XK_s)
		game->player->acc.y += MOVEMENT_ACCELERATION;
	else if (keycode == XK_F3)
		game->settings->debug_enabled = !game->settings->debug_enabled;
	else if (keycode == XK_Escape)
		exit_game(game);
	return (0);
}
