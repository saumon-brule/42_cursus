/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 07:07:42 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 12:49:39 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

#include <stdio.h>

bool	draw_game(t_game *game)
{
	draw_map(game);
	draw_player(game);
	flush_window(game);
	return (false);
}
