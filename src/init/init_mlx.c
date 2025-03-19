/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:00:53 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 22:04:07 by ebini            ###   ########lyon.fr   */
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
	if (!game->displayed)
	{
		perror("init_mlx");
		clean_mlx(game->mlx);
		return (true);
	}
	game->win = mlx_new_window(game->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
	if (!game->win)
	{
		perror("init_mlx");
		clean_mlx(game->mlx);
		mlx_destroy_image(game->mlx, game->displayed);
		return (true);
	}
	return (false);
}
