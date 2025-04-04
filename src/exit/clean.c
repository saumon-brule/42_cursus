/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:11:58 by ebini             #+#    #+#             */
/*   Updated: 2025/04/04 10:46:51 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "so_long.h"

#include <stdio.h>

void	clean_sprites(t_game *game)
{
	if (game->sprites.air)
		mlx_destroy_image(game->mlx, game->sprites.air);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.coin)
		mlx_destroy_image(game->mlx, game->sprites.coin);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->sprites.player)
		mlx_destroy_image(game->mlx, game->sprites.player);
}

void	clean_mlx(t_mlx *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}

void	clean_game_struct(t_game *game)
{
	mlx_destroy_image(game->mlx, game->displayed);
	mlx_destroy_window(game->mlx, game->win);
	clean_mlx(game->mlx);
}
