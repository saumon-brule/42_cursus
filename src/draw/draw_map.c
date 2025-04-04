/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:33:30 by saumon            #+#    #+#             */
/*   Updated: 2025/04/04 10:45:58 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"
#include "settings.h"

#include <stdio.h>

void	draw_tile(t_game *game, t_map *map, int x, int y)
{
	const char	tile = get_map(map, x, y);

	if (tile == '0')
		draw_img_on_screen(game->sprites.air, game,
			(t_tuple){x * CELL_SIZE, y * CELL_SIZE});
	else if (tile == '1')
		draw_img_on_screen(game->sprites.wall, game,
			(t_tuple){x * CELL_SIZE, y * CELL_SIZE});
	else if (tile == 'C')
		draw_img_on_screen(game->sprites.coin, game,
			(t_tuple){x * CELL_SIZE, y * CELL_SIZE});
	else if (tile == 'P')
		draw_img_on_screen(game->sprites.air, game,
			(t_tuple){x * CELL_SIZE, y * CELL_SIZE});
	else if (tile == 'E')
		draw_img_on_screen(game->sprites.exit, game,
			(t_tuple){x * CELL_SIZE, y * CELL_SIZE});
}

void	draw_map(t_game *game)
{
	const t_map	*map = &(game->map);
	int			i;
	int			j;

	j = -1;
	while (++j < (int)(game->map.height))
	{
		i = -1;
		while (++i < (int)(game->map.width))
			draw_tile(game, (t_map *)map, i, j);
	}
}
