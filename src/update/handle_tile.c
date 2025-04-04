/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:45:30 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 03:08:02 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	handle_tile(char tile, t_game *game, t_tuple new_pos)
{
	if (tile == '1')
		return (false);
	game->player_pos = new_pos;
	if (tile == 'E' && !(game->coins))
		exit_game(game);
	else if (tile == 'C')
	{
		set_map(&(game->map), new_pos.x, new_pos.y, '0');
		game->coins--;
	}
	return (true);
}
