/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:33:30 by saumon            #+#    #+#             */
/*   Updated: 2025/02/26 17:17:02 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"
#include "settings.h"

#include <stdio.h>

void	fill_image(void *addr, int color1, int color2, int line_length, int bpp)
{
	int	x;
	int	y;
	int	*pixel;

	y = WINDOW_HEIGHT;
	while (--y >= 0)
	{
		x = WINDOW_WIDTH;
		while (--x >= 0)
		{
			pixel = (int *)(addr + (y * line_length + x * (bpp / 8)));
			*pixel = (y % 50 == 0 || x % 50 == 0) ? color1 : color2;
		}
	}
}

void	draw_tile(t_game *game, t_map *map, int x, int y)
{
	const char	tile = get_map(map, x, y);

	// printf("tile[%d][%d]: %c\n", y, x, tile);
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
		{
			draw_tile(game, (t_map*)map, i, j);
		}
	}
}
