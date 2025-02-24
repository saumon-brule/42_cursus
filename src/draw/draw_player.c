/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 06:53:14 by ebini             #+#    #+#             */
/*   Updated: 2025/02/23 12:17:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "so_long.h"

void	draw_player(t_game *game)
{
	draw_img_on_screen(game->player->sprite, game, game->player->pos);
}
