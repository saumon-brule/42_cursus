/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:33:30 by saumon            #+#    #+#             */
/*   Updated: 2025/03/24 18:10:27 by ebini            ###   ########lyon.fr   */
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
		draw_img_on_screen(game->sprites->air, game, (t_point){
			(double)x * CELL_SIZE, (double)y * CELL_SIZE});
	if (tile == '1')
	{
		draw_img_on_screen(game->sprites->wall, game, (t_point){
			(double)x * CELL_SIZE, (double)y * CELL_SIZE});
	}
	if (tile == 'C')
		draw_img_on_screen(game->sprites->coin, game, (t_point){
			(double)x * CELL_SIZE, (double)y * CELL_SIZE});
}

void	draw_map(t_game *game)
{
	const t_map	*map = game->map;
	int			i;
	int			j;

	j = -1;
	while (++j < game->map->height)
	{
		i = -1;
		while (++i < game->map->width)
			draw_tile(game, (t_map *)map, i, j);
	}
}
