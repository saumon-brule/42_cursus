/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saumon <saumon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:11:58 by ebini             #+#    #+#             */
/*   Updated: 2025/02/25 20:23:59 by saumon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "so_long_defs.h"
#include "clean.h"

#include <stdio.h>

void	clean_mlx(t_mlx *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}

void	clean_sprites(t_game *game)
{
	if (game->sprites->air)
		mlx_destroy_image(game->mlx, game->sprites->air);
	if (game->sprites->wall)
		mlx_destroy_image(game->mlx, game->sprites->wall);
	if (game->sprites->coin)
		mlx_destroy_image(game->mlx, game->sprites->coin);
	free(game->sprites);
}

int	clean_to_parse(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player->sprite);
	free(game->player);
	mlx_destroy_window(game->mlx, game->win);
	clean_mlx(game->mlx);
	free(game);
	return (EXIT_FAILURE);
}

int	clean(t_game *game, unsigned int state)
{
	if (state == STATE_PARSE)
		return (clean_to_parse(game));
	return (0);
}
