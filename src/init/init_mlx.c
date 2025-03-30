/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:00:53 by ebini             #+#    #+#             */
/*   Updated: 2025/03/29 20:52:10 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "so_long.h"
#include "settings.h"

bool	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("init_mlx");
		return (true);
	}
	game->displayed = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->background = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->win = mlx_new_window(game->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
	if (!game->displayed || !game->background || !game->win)
	{
		perror("init_mlx");
		if (game->mlx)
			clean_mlx(game->mlx);
		if (game->displayed)
			mlx_destroy_image(game->mlx, game->displayed);
		if (game->background)
			mlx_destroy_image(game->mlx, game->background);
		if (game->win)
			mlx_clear_window(game->mlx, game->win);
		return (true);
	}
	return (false);
}
