/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 03:56:47 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 06:44:37 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <X11/X.h>

#include "so_long.h"
#include "events.h"

int	setup_game(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, on_key_press, game);
	mlx_hook(game->win, DestroyNotify, 0, on_destroy, game);
	return (0);
}
