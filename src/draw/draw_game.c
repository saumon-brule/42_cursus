/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 07:07:42 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 14:40:29 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"

bool	draw_game(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->displayed, 0, 0);
	draw_map(game);
	draw_player(game);
	return (false);
}
