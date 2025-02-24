/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:25:35 by ebini             #+#    #+#             */
/*   Updated: 2025/02/21 02:42:31 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/keysym.h>

#include "so_long.h"
#include "settings.h"

#include <stdio.h>

int	on_key_press(int keycode, t_game *game)
{
	if (keycode == XK_q)
		game->player->acc.x -= MOVEMENT_ACCELERATION;
	if (keycode == XK_d)
		game->player->acc.x += MOVEMENT_ACCELERATION;
	else if (keycode == XK_Escape)
		exit_game(game);
	return (0);
}
