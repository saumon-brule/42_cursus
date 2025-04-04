/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:30:45 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 13:09:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	const t_tuple	new_pos = {
		game->player_pos.x + dx, game->player_pos.y + dy};
	const char		tile = get_map(&(game->map), new_pos.x, new_pos.y);

	if (handle_tile(tile, game, new_pos))
	{
		draw_player(game);
		draw_tile(game, &(game->map),
			game->player_pos.x - dx, game->player_pos.y - dy);
		flush_window(game);
	}
	game->action_count++;
	ft_printf("%d\n", game->action_count);
}
