/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:25:35 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 23:17:00 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/keysym.h>

#include "so_long.h"
#include "settings.h"

#include <stdio.h>

int	on_key_release(int keycode, t_game *game)
{
	if (keycode == XK_a)
		game->player->acc.x += MOVEMENT_ACCELERATION;
	else if (keycode == XK_d)
		game->player->acc.x -= MOVEMENT_ACCELERATION;
	else if (keycode == XK_w)
		game->player->acc.y += MOVEMENT_ACCELERATION;
	else if (keycode == XK_s)
		game->player->acc.y -= MOVEMENT_ACCELERATION;
	return (0);
}
